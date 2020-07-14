/* fscanf, fprintf로 파일 입출력 해보기 
system() 써서 메모장 오픈하는 기능도 있삼
fscanf 세 번 호출하지 말고 한 줄로 줄여도 됬겠다
원래 있던 폴더에서 이 솔루션으로 복사해오니깐, 파일입출력하는 부분에서 런타임에러가 떴는데
텍스트파일을 여기 비주얼 스튜디오에서 솔루션에는 복붙해줬지만 실제 폴더에는 복붙안해줌.
탐색기에서 경로 따라가서 솔루션있는 디렉토리에 텍스트파일 복붙해주니까 해결완료요 
*/
#include <stdio.h>

int main() {
	FILE* stream1 = fopen("studentscore.txt", "r");
	FILE* stream2 = fopen("report.txt", "w");
	int stdnum, fscore, sscore, sum;
	
	for (int i = 0; i < 5; i++) {
		fscanf(stream1, "%d", &stdnum);
		fscanf(stream1, "%d", &fscore);
		fscanf(stream1, "%d", &sscore);
		sum = fscore + sscore;
		fprintf(stream2, "학생번호: %2d, 시험1: %3d, 시험2: %3d, 총점: %3d\n", stdnum, fscore, sscore, sum);
	}
	fclose(stream1);
	fclose(stream2);
	system("notepad.exe report.txt");
	return 0;
}