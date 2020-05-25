新建一个对话框的MFC工程，在CMemoryLeakDlg::OnInitDialog分配内存，但是不释放，编译后输出
就会报错内存泄漏：

Detected memory leaks!
Dumping objects ->
{379} normal block at 0x0062CC48, 8 bytes long.
 Data: <@ b     > 40 1A 62 00 00 00 00 00 
d:\王健伟学习笔记\第5章mfc程序观察内存泄漏\memoryleak\memoryleakdlg.cpp(105) : {378} normal block at 0x00621A40, 28 bytes long.
 Data: <H b jisuanjiz   > 48 CC 62 00 6A 69 73 75 61 6E 6A 69 7A 00 CD CD 
Object dump complete.