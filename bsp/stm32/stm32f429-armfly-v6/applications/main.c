#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "paho_mqtt.h"
// #include "wifi_config.h"

#include "aht10.h"
#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

#include <cJSON.h>

/**
 * MQTT URI farmat:
 * domain mode
 * tcp://iot.eclipse.org:1883
 *
 * ipv4 mode
 * tcp://192.168.10.1:1883
 * ssl://192.168.10.1:1884
 *
 * ipv6 mode
 * tcp://[fe80::20c:29ff:fe9a:a07e]:1883
 * ssl://[fe80::20c:29ff:fe9a:a07e]:1884
 */
#define MQTT_URI "tcp://192.168.1.110:1883"
#define MQTT_USERNAME "panduola"
#define MQTT_PASSWORD "panduola"
#define MQTT_SUBTOPIC "/test/topic2"
#define MQTT_PUBTOPIC "/test/topic1"

#define LED_PIN GET_PIN(E, 8)

/* define MQTT client context */
static MQTTClient client;
static void mq_start(void);
static void mq_publish(const char *send_str);

char sup_pub_topic[48] = MQTT_PUBTOPIC;
char sup_sub_topic[48] = MQTT_SUBTOPIC;

static void mqtt_sub_callback(MQTTClient *c, MessageData *msg_data)
{
    printf("Receive message ,Topic: %.*s,payload:\n", msg_data->topicName->lenstring.len, msg_data->topicName->lenstring.data);
    // ??JSON??
    cJSON *json_obj = cJSON_Parse((const char *)msg_data->message->payload);
    if (json_obj == NULL)
    {
        printf("Failed to parse JSON message\n");
        return;
    }
    cJSON *object = RT_NULL;
    object = cJSON_GetObjectItem(json_obj, "location");
    if (object != NULL)
    {

        printf("Location: %s\n", object->valuestring);
    }
    object = cJSON_GetObjectItem(json_obj, "led");
    if (object != NULL)
    {
        if (object->type == cJSON_True)
        {
            printf("led: ture\n");
            rt_pin_write(LED_PIN, PIN_LOW);
        }

        else
        {
            printf("led: false\n");
            rt_pin_write(LED_PIN, PIN_HIGH);
        }
    }

    cJSON_Delete(json_obj);

    return;
}

static void mqtt_sub_default_callback(MQTTClient *c, MessageData *msg_data)
{
    *((char *)msg_data->message->payload + msg_data->message->payloadlen) = '\0';
    LOG_D("mqtt sub default callback: %.*s %.*s",//%.*s ??????????????????
          msg_data->topicName->lenstring.len,
          msg_data->topicName->lenstring.data,
          msg_data->message->payloadlen,
          (char *)msg_data->message->payload);
    return;
}

static void mqtt_connect_callback(MQTTClient *c)
{
    LOG_I("Start to connect mqtt server");
}

static void mqtt_online_callback(MQTTClient *c)
{
    LOG_D("Connect mqtt server success");
    LOG_D("Publish message: Hello,RT-Thread! to topic: %s", sup_pub_topic);
    mq_publish("Hello,RT-Thread!");
}

static void mqtt_offline_callback(MQTTClient *c)
{
    LOG_I("Disconnect from mqtt server");
}

/* ????? mqtt ??? */
static void mq_start(void)
{
    /* ?? condata ?? */
    MQTTPacket_connectData condata = MQTTPacket_connectData_initializer;
    static char cid[20] = {0};

    static int is_started = 0;
    if (is_started)
    {
        return;
    }
    /* ?? MQTT ???? */
    {
        client.isconnected = 0;
        client.uri = MQTT_URI;

        /* ??????? ID */
        rt_snprintf(cid, sizeof(cid), "rtthread%d", rt_tick_get());

        // rt_snprintf(sup_pub_topic, sizeof(sup_pub_topic), "%s%s", MQTT_PUBTOPIC, cid);
        /* ?????? */
        memcpy(sup_pub_topic, MQTT_SUBTOPIC, sizeof(MQTT_SUBTOPIC));
        memcpy(&client.condata, &condata, sizeof(condata));
        client.condata.clientID.cstring = cid;
        client.condata.keepAliveInterval = 60;
        client.condata.cleansession = 1;
        client.condata.username.cstring = MQTT_USERNAME;
        client.condata.password.cstring = MQTT_PASSWORD;

        /* ?? mqtt ?? */
        client.condata.willFlag = 0;
        client.condata.will.qos = 1;
        client.condata.will.retained = 0;
        client.condata.will.topicName.cstring = sup_pub_topic;

        client.buf_size = client.readbuf_size = 1024;
        client.buf = malloc(client.buf_size);
        client.readbuf = malloc(client.readbuf_size);
        if (!(client.buf && client.readbuf))
        {
            LOG_E("no memory for MQTT client buffer!");
            goto _exit;
        }

        /* ?????? */
        client.connect_callback = mqtt_connect_callback;
        client.online_callback = mqtt_online_callback;
        client.offline_callback = mqtt_offline_callback;
        /* ?????? topic ? topic ??????? */
        client.messageHandlers[0].topicFilter = MQTT_SUBTOPIC;
        client.messageHandlers[0].callback = mqtt_sub_callback;
        client.messageHandlers[0].qos = QOS1;

        /* ?????????? */
        client.defaultMessageHandler = mqtt_sub_default_callback;
    }

    /* ?? MQTT ??? */
    LOG_D("Start mqtt client and subscribe topic:%s", sup_pub_topic);
    paho_mqtt_start(&client);
    is_started = 1;

_exit:
    return;
}

/* MQTT ?????? */
static void mq_publish(const char *send_str)
{
    MQTTMessage message;
    const char *msg_str = send_str;
    const char *topic = MQTT_PUBTOPIC;
    message.qos = QOS1;
    message.retained = 0;
    message.payload = (void *)msg_str;
    message.payloadlen = strlen(message.payload);

    MQTTPublish(&client, topic, &message);

    return;
}

rt_thread_t TH_Get_HU;
rt_thread_t Publish_value;
float humidity, temperature;

void get_humi_temp(void *parameter)
{

    aht10_device_t dev;

    const char *i2c_bus_name = "i2c2";
    int count = 0;

    rt_thread_mdelay(2000);

    dev = aht10_init(i2c_bus_name);
    if (dev == RT_NULL)
    {
        LOG_E(" The sensor initializes failure");
    }

    while (count++ < 100)
    {

        humidity = aht10_read_humidity(dev);
        // LOG_D("humidity   : %d.%d %%", (int)humidity, (int)(humidity * 10) % 10);

        temperature = aht10_read_temperature(dev);
        // LOG_D("temperature: %d.%d", (int)temperature, (int)(temperature * 10) % 10);

        rt_thread_mdelay(1000);
    }
}

void Publish_Date(void *parameter)
{
    char send_str[128];
    while (1)
    {
        // sprintf(send_str, "{\"temperature\":%d.%d,\"humidity\":%d.%d}", (int)temperature, (int)(temperature * 10) % 10, (int)humidity, (int)(humidity * 10) % 10);

        sprintf(send_str, "{\"location\":\"10#A401\",\"led\":true,\"environment\":{\"temperature\":%d.%d,\"humidity\":%d.%d}}", (int)temperature, (int)(temperature * 10) % 10, (int)humidity, (int)(humidity * 10) % 10);
        mq_publish(send_str);
        rt_thread_mdelay(1000);
    }
}

int main(void)
{
    mq_start();
    TH_Get_HU = rt_thread_create("get_humi_temp", get_humi_temp, RT_NULL, 1024, 20, 10);
    Publish_value = rt_thread_create("Publish_value", Publish_Date, RT_NULL, 1024, 20, 10);
    rt_pin_mode(LED_PIN, PIN_MODE_OUTPUT);
    rt_thread_startup(TH_Get_HU);
    rt_thread_mdelay(1000);
    rt_thread_startup(Publish_value);
}

