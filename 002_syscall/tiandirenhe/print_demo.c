#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    const char* nickname = "tiandirenhe\n";//��������ָ���Ļ�������Ҫ������ַ�������ô���
    size_t bytes = strlen(nickname);//���������ַ�������Ч�ַ��ĸ�������strlen()��������ָ�����ַ���s�ĳ��ȣ������������ַ�"\0"��
    ssize_t  ret = write(STDOUT_FILENO, nickname, bytes);//����һ:�����ļ���������STDOUT_FILENO�Ǵ����ļ���������ŵĺꡣ

    //write��������ֵ��д���ĵ����ֽ������ɹ�����-1������
    if(-1 == ret)
    {
        perror("write error!\n"); //perror ( )�� �� �� �� һ �� �� �� �� �� �� �� �� ԭ �� �� �� �� �� ׼ �豸 (stderr)
    }

    return 0;
}
