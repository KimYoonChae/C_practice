#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findRoom(int persons[5]); // 5개의 호실 중 빈 베드가 있는 방을 찾아낸다. (리턴값 1~5)
void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc); // 배정 결과를 출력한다.

int main(){
	char mnames[10][20]; // 남학생명단(최대 10명)
	int mroom[10];		// 남학생명단별 호실 배정 목록
	char wnames[10][20]; // 여학생명단(최대 10명)
	int wroom[10];		// 여학생명단별 호실 배정 목록
	int person[2][5]={0};   // 2개 층별 5개 호실의 배정 인원 수 
	int mcount=0, wcount=0; // 인원 합계 (남, 여)
	int menu;

	srand(time(0));
	printf("===========================================\n");
	printf("생활관 호실 배정 프로그램\n");
	printf("===========================================\n");
	while(1){
		printf("메뉴 : 1.남학생 등록 2.여학생 등록 0.종료 > ");
		scanf("%d", &menu);
		if(menu==0) break;
		else if(menu==1) {
			if(mcount>=10) {
				printf("정원 초과입니다. 등록불가!\n");
				continue;
			}
			printf("학생 이름은? > ");
			scanf("%s", mnames[mcount]);
			int roomno = findRoom(person[0]);
			mroom[mcount] = 100+roomno;
			printf("%s 학생 %d호실 배정되었습니다.\n", mnames[mcount], mroom[mcount]);
			mcount++;
		}
		else if(menu==2) {
			if(wcount>=10) {
				printf("정원 초과입니다. 등록불가!\n");
				continue;
			}
			printf("학생 이름은? > ");
			scanf("%s", wnames[wcount]);
			int roomno = findRoom(person[1]);
			wroom[wcount] = 200+roomno;
			printf("%s 학생 %d호실 배정되었습니다.\n", wnames[wcount], wroom[wcount]);
			wcount++;
		}
	}

	printf("===========================================\n");
	printf("생활관 호실 배정 결과는 다음과 같습니다.\n");
	printf("===========================================\n");
	printReport(mnames, mroom, mcount, wnames, wroom, wcount);

	return 0;
}

/*배정할 호실 찾기 함수*/
int findRoom(int persons[5]){
int roomno=0; //호실 번호를 0으로 초기화 한다.
while(1){
    roomno = rand()%5+1; //호실 번호를 1~5중에 랜덤으로 배정한다.
    if(persons[roomno]<2) //만약 5개의 호실 내에 이미 배정된 사람의 숫자 배열의 요소가 2명을 넘지 않다면, 그 요소의 수를 하나 늘리고 반복문을 빠져나온다.
    {
        persons[roomno]++;
        break;
    }
} 
return roomno; //호실번호를 리턴한다.
}

/*배정 결과 출력하기 함수*/
//파라미터: 남학생이름 배열, 남학생 배정된 호실번호 배열, 등록된 남학생 수, 여학생이름 배열, 여학생 배정 된 호실번호 배열, 등록된 여학생 수
void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc){
	/* 
	   남학생, 여학생 명단 출력
	   - for문을 이용하여 등록된 전체 남학생 수와 여학생 수만큼 반복하며 명단 출력한다.
	*/
    printf("남학생 명단 (%d명)\n",mc);
    for(int i=0;i<mc;i++){
        printf("%d. %s [%d호]\n",i+1,mn[i],mr[i]);
    }
    printf("\n");

    printf("여학생 명단 (%d명)\n",wc);
    for(int i=0;i<wc;i++){
        printf("%d. %s [%d호]\n",i+1,wn[i],wr[i]);
    }

	 /* 
       호실별 배정 명단 출력
       -101호부터 105호까지 반복하며 호실에 배정된 남학생을 출력한다.
	   -201호부터 205호까지 반복하며 호실에 배정된 여학생 출력한다.
    */
    printf("\n호실별 배정 명단\n");
    for(int i=101;i<=105;i++)
    {
        printf("%d호 : ",i); //호실 번호 출력하기
        for(int j=0;j<mc;j++){ //등록한 남학생들 중에서 만약 호실 번호랑 일치하면 이름을 출력한다.
            if(mr[j]==i)
            {
                printf("%s ",mn[j]);
            }
        }
        printf("\n");
    }
     for(int i=201;i<=205;i++)
    {
        printf("%d호 : ",i); //호실 번호 출력하기
        for(int t=0;t<wc;t++){ //등록한 여학생들 중에서 만약 호실 번호랑 일치하면 이름을 출력한다.
            if(wr[t]==i)
            {
                printf("%s ",wn[t]);
            }
        }
        printf("\n");
    }
    
}