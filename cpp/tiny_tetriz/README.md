# 俄罗斯方块

在终端实现俄罗斯方块的小游戏

## ANSI控制

> https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797

1. 控制终端颜色输出
e.g: printf  \\x1b[1\;31mHelloWorld]
2. 控制光标出现位置
printf  \\033[5\;10HhelloWorld
printf  \\033[15\;10HhelloWorld
3. 清屏函数
ESC[2J
printf \\033[2J
所以先清屏，再把光标移动到第5行第10列即可实现组合效果
4. 以及颜色设置以及背景色设置, 此处不表
5. 隐藏/恢复 光标(不好使
hide: printf \\033[?25l
recover: printf \\033[?25h


