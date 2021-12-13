from os import system, remove, getcwd, chdir, path
from sys import exit, executable
from time import sleep
from msvcrt import getch
from requests import post, get
# 直接运行代码可能会出现路径在 PythonSoftwareFoundation 中，请修改这一部分
path = path.dirname(path.realpath(executable)) + '\\secrets.d'


def checkfile():
    try:
        with open(path, 'r') as f:
            data = f.readlines()
            try:
                ddddd = data[0].strip().split('=')[1]
                upass = data[1].strip().split('=')[1]
                if ddddd == '' or upass == '':
                    raise Exception
            except:
                return False
            return [ddddd, upass]
    except:
        return False


def login(ddddd, upass):
    print('正在登录...')
    url = 'http://172.30.255.2/0.htm'
    req = {'DDDDD': ddddd, 'upass': upass, '0MKKey': '123456'}
    r = post(url, data=req)
    if '登录成功窗' in r.text:
        print('登录成功！')
        sleep(0.6)
    else:
        if 'userid error1' in r.text:
            print('登录失败：用户名错误！按任意键重新输入，按 Esc 退出。')
        elif 'ldap auth error' in r.text:
            print('登录失败：密码错误！按任意键重新输入，按 Esc 退出。')
        remove(path)
        if getch() == b'\x1b':
            exit()
        start()


def logout():
    url = 'http://172.30.255.2/F.htm'
    get(url)
    print('已退出登录。')
    sleep(1)


def start():
    system('cls')
    file = checkfile()
    print('-------- Dr.com 一键登录 by AnotiaWang 2021 --------\n')
    if file:
        ddddd, upass = file
        login(ddddd, upass)
    else:
        ddddd = input('请输入学号：')
        upass = input('请输入密码：')
        print('登录信息将保存在 ' + path + ' ，下次运行时会自动尝试登录。（数据明文保存，请保护好文件）\n确认？(Enter/Y/N) ')
        confirm = getch()
        if confirm == 'y' or confirm == 'Y' or confirm == b'\r':
            open(path, 'w').write('DDDDD=' + ddddd + '\nupass=' + upass)
            login(ddddd, upass)
        else:
            print('已取消。按任意键重新输入，按 Esc 退出。')
            if getch() == b'\x1b':
                exit()
            start()


start()
