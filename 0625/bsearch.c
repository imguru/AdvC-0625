// 아래 코드는 문제가 있습니다.
//  어떤 문제가 있을까요?
int search(int* ar, int len, int target){
	int first = 0;
	int last = len - 1;
	int mid = 0;

	while (first <= last){
		// mid = (first + last) / 2;
		mid = (unsigned)(first + last) >> 1;
		if (ar[mid] == target){
			return mid;
		}
		else{
			if (ar[mid] > target)
				last = mid - 1;
			else
				first = mid + 1;
		}
	}
	return -1;
}

