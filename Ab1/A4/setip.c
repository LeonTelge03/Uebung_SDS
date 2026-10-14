//IN LINUX!!!
#define _DEFAULT_SOURCE
#include <arpa/inet.h>
#include <errno.h>
#include <error.h>
#include <net/if.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>


void usage() {
    puts("setip INTERFACE ADRESS");
}

void set_ip(const char *ip, const char *dev) {
    struct ifreq ifr;
    int fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd < 0) error(errno, errno, "socket");

    strncpy(ifr.ifr_name, dev, IFNAMSIZ);
    struct sockaddr_in *addr = (struct sockaddr_in *) &ifr.ifr_addr;

    addr->sin_family = AF_INET;
    addr->sin_addr.s_addr = inet_addr(ip);

    if (ioctl(fd, SIOCSIFADDR, &ifr) ==-1) error(0, errno, "SIOCSIFADDR");
    close(fd);
}

int get_numbers(char* IpAdresse, int ip[4]) {
    char* p = IpAdresse;
    int i = 0,k = 0;
    while(*p) {
        if(*p >= '0'||*p <= '9') {
            ip[i] = ip[i]*(10^k) + *p-48;
            k++;
        } else {
            if(*p == '.' && i < 4) {
            i++;
            k = 0;
            } else if(*p != '\n') {
            return 0;
            }
        }
        p++;
    }
    return 1;
}

int main(int args, char* argv[]) {
    if(args != 3)
        usage();
    int ip[4] = {0,0,0,0};

    if(!get_numbers(argv[2], ip)) {
        puts("IP must match *.*.*.*");
        puts("but is:"),
        puts(argv[2]);
        return 1;
    }
    //strcpy(("%u.%u.%u.%u",ip[0],ip[1],ip[2],ip[3]),argv[2]);

    printf("IP: %u.%u.%u.%u\n",ip[0],ip[1],ip[2],ip[3]);
    if(ip[0] <=255 && ip[1] <=255 && ip[2] <=255 && ip[3] <=255)
        set_ip(argv[2], argv[1]);
    return 0;
}