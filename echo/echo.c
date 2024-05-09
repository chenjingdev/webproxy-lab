#include "csapp.h" // csapp.h 헤더 파일 포함

void echo(int connfd) // 에코 함수 정의
{
    size_t n;          // 읽은 바이트 수 저장 변수
    char buf[MAXLINE]; // 데이터 버퍼
    rio_t rio;         // Rio 구조체

    Rio_readinitb(&rio, connfd);                         // Rio 구조체 초기화
    while ((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0) // 데이터 읽기, 0이 될 때까지 반복
    {
        printf("server received %d bytes\n", (int)n); // 서버가 받은 바이트 수 출력
        Rio_writen(connfd, buf, n);                   // 읽은 데이터를 다시 클라이언트에 전송
    }
}
