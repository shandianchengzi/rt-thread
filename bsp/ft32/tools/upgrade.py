#
# File      : upgrade.py
# This file is part of RT-Thread RTOS
# COPYRIGHT (C) 2006 - 2021, RT-Thread Development Team
#
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License along
#  with this program; if not, write to the Free Software Foundation, Inc.,
#  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
#
# Change Logs:
# Date           Author       Notes
# 2021-10-11     Meco Man     First version
#

# HAL
# 1.gccmainentry
# 2.heap0(Keil IAR)
# 3.GCC0x400Keil IAR


#bsp/ft32C:\Users\92036\Desktop\rt-thread\bsp\ft32

import os
import re

#'bl main'  'bl entry'
def main2entry(path):
    oldline = ''
    newline = ''

    for root, dirs, files in os.walk(path): #
        for file in files:
            if os.path.splitext(file)[1] == '.s': #.s
                file_path = os.path.join(root,file)
                flag_need_replace = False
                with open(file_path,'r+',) as f:
                    while True:
                        line = f.readline()
                        if line == '':
                            break
                        elif ('bl' in line) and ('main' in line): #'bl main'
                            oldline = line # bl main
                            newline = line.replace('main', 'entry') #mainentry
                            flag_need_replace = True #entry
                            break

                    if (flag_need_replace == True): #mainentry
                        f.seek(0)
                        content = f.read()
                        f.seek(0)
                        f.truncate()
                        newcontent = content.replace(oldline, newline)
                        f.write(newcontent)

#heap0
def heap2zero(path):
    oldline = ''
    newline = ''
    for root, dirs, files in os.walk(path): #
        for file in files:
            file_path = os.path.join(root,file)
            if os.path.splitext(file)[1] == '.s': #.s
                with open(file_path,'r+',) as f:
                    flag_need_replace = False
                    while True:
                        line = f.readline()
                        if line == '':
                            break

                        re_result = re.match('\s*Heap_Size\s+EQU\s+0[xX][0-9a-fA-F]+', line) #MDK
                        if re_result != None:
                            oldline = line
                            newline = re.sub('0[xX][0-9a-fA-F]+','0x00000000', oldline)
                            flag_need_replace = True
                            break

                    if flag_need_replace == True:
                        f.seek(0)
                        content = f.read()
                        f.seek(0)
                        f.truncate()
                        newcontent = content.replace(oldline, newline)
                        f.write(newcontent)

            elif os.path.splitext(file)[1] == '.icf': #.icf(IAR)
                with open(file_path,'r+',) as f:
                    flag_need_replace = False
                    while True:
                        line = f.readline()
                        if line == '':
                            break

                        re_result = re.match('\s*define\s+symbol\s+__ICFEDIT_size_heap__\s*=\s*0[xX][0-9a-fA-F]+', line) #IAR
                        if re_result != None:
                            oldline = line
                            newline = re.sub('0[xX][0-9a-fA-F]+','0x000', oldline)
                            flag_need_replace = True
                            break

                    if flag_need_replace == True:
                        f.seek(0)
                        content = f.read()
                        f.seek(0)
                        f.truncate()
                        newcontent = content.replace(oldline, newline)
                        f.write(newcontent)

            elif os.path.splitext(file)[1] == '.lds': #.lds(GCC)
                with open(file_path,'r+',) as f:
                    flag_need_replace = False
                    while True:
                        line = f.readline()
                        if line == '':
                            break

                        re_result = re.match('\s*_system_stack_size\s*=\s*0[xX][0-9a-fA-F]+', line) #GCC, 0x400
                        if re_result != None:
                            oldline = line
                            newline = re.sub('0[xX][0-9a-fA-F]+','0x400', oldline)
                            flag_need_replace = True
                            break

                    if flag_need_replace == True:
                        f.seek(0)
                        content = f.read()
                        f.seek(0)
                        f.truncate()
                        newcontent = content.replace(oldline, newline)
                        f.write(newcontent)

folder_path = input('please input path:')
main2entry(folder_path)
heap2zero(folder_path)
