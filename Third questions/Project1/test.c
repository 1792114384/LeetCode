#include <stdio.h>
#include <string.h>

//int IsUnique(char *s, int i, int j)
//{
//	for (int k = i; k < j; k++)
//	{
//		if (s[j] == s[k]) return 0;
//	}
//	return 1;
//}
//
//int lengthOfLongestSubstring(char* s) {
//	int length = strlen(s);
//	int max = 0;
//	for (int i = 0; i < length; i++)
//	{
//		for (int j = i + 1; j <= length; j++)
//		{
//			if (IsUnique(s, i, j))
//			{
//				max = (j - i) > max ? (j - i) : max;
//			}
//			else
//			{
//				max = (j - i) > max ? (j - i) : max;
//				break;
//			}
//		}
//	}
//	return max;
//}

int lengthOfLongestSubstring(char* s)
{
	int Hash[128] = { 0 };
	int max = 0;
	int start = 0;
	int i = 0;
	int length = strlen(s);
	while (i < length && start < length)
	{
		if (Hash[s[start]] == 0) {
			Hash[s[start]] = 1;
			start++;
			max = (start - i) > max ? (start - i) : max;
		}
		else {
			Hash[s[i]] = 0;
			i++;
		}
	}
	return max;
}

int main()
{
	char *s = "pwwetra";
	int max = lengthOfLongestSubstring(s);
	printf("%d\n", max);
	system("pause");
	return 0;
}