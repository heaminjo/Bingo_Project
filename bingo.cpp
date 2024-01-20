#include <stdio.h>
#include<Windows.h>
#define C 5
#define R 5

int count=0;

//빙고판 출력
void print(int bingo[][C]) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			printf("%d\t", bingo[i][j]);
		}
		printf("\n");
		printf("\n");
		printf("\n");
	}
}

//빙고 체크
int count_bingo(int(*bingo)[C]) {
	int check = 0;    //한줄이 모두 0일때 체크
	int row=0;        //가로줄 빙고 
	int col=0;        //세로줄 빙고
	int left_cross=0; //왼쪽 대각선 빙고
	int right_cross=0;//오른쪽 대각선 빙고
	for (int i = 0; i < R; i++) {  
		row = col = 0;           
		for (int j = 0; j < C; j++) {
			if (bingo[i][j] == 0) {  //가로줄의 0의 개수 체크
				row++;               
			}
			if (bingo[j][i] == 0) {  //세로줄의 0의개수
				col++;
			}
		}
		if (bingo[i][i] == 0) {   //왼쪽 대각선의 0의개수
			left_cross++;
		}
		if (bingo[i][C - 1 - i] == 0) { //오른쪽 대각선의 0의개수
			right_cross++;
		}
		if (row == R) {   //가로줄의 0의개수가 5라면 check
			check++;
		}
		if (col == R) {  //세로줄의 0의개수가 5라면 check
			check++;
		}
	}
	if (left_cross == R) { //대각선 check
		check++;
	}
	if (right_cross == R) {
		check++;
	}
	return check; //반환
}

//번호 체크
int check_bingo(int (*bingo)[C], int number) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (bingo[i][j] == number) {
				bingo[i][j] = 0;
				return 0;
			}
		}
	}
	printf("해당 번호는 없는 번호입니다. 다시 입력해주세요.\n");
}
int main(void) {
	int check;        //전체 빙고판의 빙고 개수를 반환 받을 변수
	int check2 = 1;   //count를 올릴 조건

	int bingo[R][C] = {
		{25,3,7,4,14},
		{32,6,1,23,75},
		{42,57,16,2,8},
		{12,65,26,53,31},
		{9,5,34,63,19}
	};

	
	int number;

	printf("\t    ★빙고게임★\n");
	printf("====================================\n");
	while (1) {
		print(bingo);
		printf("현재 카운트:%d\n", count);

		printf("번호:");
		scanf_s("%d", &number);
		
		check_bingo(bingo, number);//번호 체크

		check = count_bingo(bingo); //빙고 체크
		                            //빙고된 개수를 check에 반환

		if (check == check2) {  
			//한번 0이 된 자리는 계속 0이기때문에
			//반환 받는 check는 계속해서 
			//전체 빙고판의 빙고개수를 반환할것이다.
			//새로운 빙고가 발생할경우에만 count를 올리기위해서
			//check2를 만들어 두 변수의 값이 같을경우에만 
			//count를 올리도록 하고 check2를 1 증가

			//하면 새로운 빙고가 발생하지않을 경우 check는 그대로일것이고
			//새로운 빙고가 발생할 경우 if문을 만족하여
			//count 증가 
			count++;
			check2++;
		}
		system("pause");
		system("cls");
	}
	return 0;
}