#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#define MAXSIZE 1024     /*�������ݻ�������С*/

int main(int argc, char *argv[])
{
int sockfd,new_fd;
struct sockaddr_in server_addr;   /*������������׽ӿ����ݽṹserver_addr */
struct sockaddr_in client_addr;   /*����ͻ����׽ӿ����ݽṹclient_addr */
int sin_size,portnumber; 
char buf[MAXSIZE];     /*�������ݻ�����*/
if(argc!=2)
{
fprintf(stderr,"Usage:%s portnumber\a\n",argv[0]);
exit(1);
}
if((portnumber=atoi(argv[1]))<0) 
{  /*��������еĵڶ�������--�˿ںţ�atoi()���ַ���ת����������*/
fprintf(stderr,"Usage:%s portnumber\a\n",argv[0]);
exit(1);
}
if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
/*�������˿�ʼ����socket������*/
{
fprintf(stderr,"Socket error:%s\n\a",strerror(errno));
exit(1);
} 
/*����������� sockaddr�ṹ*/
bzero(&server_addr,sizeof(struct sockaddr_in)); /*�Ƚ��׽ӿڵ�ַ���ݽṹ����*/
server_addr.sin_family=AF_INET;
server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
server_addr.sin_port=htons(portnumber);
if(bind(sockfd,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr))==-1)
                                   /*����bind�����󶨶˿�*/
{ 
fprintf(stderr,"Bind error:%s\n\a",strerror(errno)); 
exit(1); 
} 
if(listen(sockfd,5)==-1)  
/*�˿ڰ󶨳ɹ�������sockfd��������ͬʱ������������������Ϊ5 */
{
fprintf(stderr,"Listen error:%s\n\a",strerror(errno));
exit(1);
}
while(1)      /*�������������ȴ�������������ֱ���ͻ���������������*/
{
sin_size=sizeof(struct sockaddr_in);
if((new_fd=accept(sockfd,(struct sockaddr *)(&client_addr),&sin_size))==-1)
/*����accept����һ����������*/
{
fprintf(stderr,"Accept error:%s\n\a",strerror(errno)); 
exit(1); 
}
fprintf(stderr,"Server get connection from %s\n",inet_ntoa(client_addr.sin_addr));
/*TCP�����ѽ�������ӡ�������ӵĿͻ�����IP��ַ*/
printf("Connected successful, please input the masage[<1024 bytes]:\n");
        /*��ʾ�û����뽫Ҫ���͵����ݣ�����С�ڻ������ĳ��ȣ���1024�ֽ�*/
if(fgets(buf, sizeof(buf), stdin) != buf)
{  /*���ն���������ݴ����buf������*/
         printf("fgets error!\n");
         exit(1);
}
if(write(new_fd,buf,strlen(buf))==-1)   /*����write��������*/
{
fprintf(stderr,"Write Error:%s\n",strerror(errno)); 
exit(1); 
} 
close(new_fd);  /*����ͨ���ѽ������رտͻ��˵��׽ӿڣ���ѭ����һ�εȴ�*/
}
close(sockfd);  /*���������̽������رշ��������׽ӿ�*/
exit(0);
}
