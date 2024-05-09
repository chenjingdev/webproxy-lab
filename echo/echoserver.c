#include "csapp.h" // csapp.h 헤더 파일 포함

void echo(int connfd); // echo 함수 선언

int main(int argc, char **argv) // 메인 함수, 프로그램 시작점
{
    int listenfd, connfd;                                // 리스닝 및 연결 소켓 파일 디스크립터
    socklen_t clientlen;                                 // 클라이언트 주소 구조체의 크기
    struct sockaddr_storage clientaddr;                  // 클라이언트 주소 정보 저장을 위한 구조체
    char client_hostname[MAXLINE], client_port[MAXLINE]; // 클라이언트 호스트 이름과 포트

    if (argc != 2) // 인자의 개수가 2가 아닐 경우 오류 메시지 출력
    {
        fprintf(stderr, "usage: %s <port>\n", argv[0]); // 사용 방법 안내
        exit(0);                                        // 프로그램 비정상 종료
    }

    listenfd = Open_listenfd(argv[1]); // 지정된 포트에서 듣기 소켓 오픈
    while (1)                          // 무한 루프로 클라이언트의 연결을 받음
    {
        clientlen = sizeof(struct sockaddr_storage);                                                  // 클라이언트 주소 구조체의 크기
        connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);                                     // 클라이언트 연결 수락
        Getnameinfo((SA *)&clientaddr, clientlen, client_hostname, MAXLINE, client_port, MAXLINE, 0); // 클라이언트의 호스트 이름과 포트 정보 가져오기
        printf("Connected to (%s, %s)\n", client_hostname, client_port);                              // 연결 정보 출력
        echo(connfd);                                                                                 // 에코 함수 호출로 데이터 송수신 처리
        Close(connfd);                                                                                // 연결 소켓 닫기
    }
    exit(0); // 프로그램 종료
}
