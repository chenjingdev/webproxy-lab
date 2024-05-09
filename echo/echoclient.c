#include "csapp.h" // csapp.h 헤더 파일 포함, 네트워크 및 입출력 함수 사용을 위함

int main(int argc, char **argv) // 메인 함수, 프로그램 시작점
{
    int clientfd;                    // 클라이언트 소켓 파일 디스크립터
    char *host, *port, buf[MAXLINE]; // 호스트, 포트 문자열 포인터 및 입력 버퍼
    rio_t rio;                       // Rio 구조체, 효율적인 입출력을 위한 타입

    if (argc != 3) // 인자의 개수가 3이 아닐 경우 오류 메시지 출력
    {
        fprintf(stderr, "usage: %s <host> <port>\n", argv[0]); // 사용 방법 안내
        exit(0);                                               // 프로그램 비정상 종료
    }
    host = argv[1]; // 첫 번째 인자로 호스트 이름 설정
    port = argv[2]; // 두 번째 인자로 포트 번호 설정

    clientfd = Open_clientfd(host, port); // 서버에 연결하는 소켓 생성
    Rio_readinitb(&rio, clientfd);        // Rio 구조체 초기화

    while (Fgets(buf, MAXLINE, stdin) != NULL) // 표준 입력으로부터 한 줄 읽기
    {
        Rio_writen(clientfd, buf, strlen(buf)); // 읽은 데이터를 서버로 전송
        Rio_readlineb(&rio, buf, MAXLINE);      // 서버로부터 데이터 읽기
        Fputs(buf, stdout);                     // 읽은 데이터를 표준 출력에 출력
    }
    Close(clientfd); // 소켓 연결 종료
    exit(0);         // 프로그램 정상 종료
};
