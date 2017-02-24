#include <iostream>
using namespace std;
int main(){
	string text,pat;
	getline(std::cin,text);
	getline(std::cin,pat);
	int n=text.length();
	int lps[n],len=0,i=0;
	lps[0]=0;
	i++;
	while(i<n){
		while(text[i]==text[len]){
			len++;
			lps[i]=len;
			i++;
		}
		if(len!=0){
			len=lps[i--]
		}
		else{
			lps[i]=0;
			i++;
		}
	}
	i=0;
	int j=0;
	while(i<text.lenth()){
		if(text[i]==pat[j]){
			i++;j++;
		}
		if(j==n){
			//found
			j=lps[j-1];
		}
		else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j-1];
            else
                i++;
        }
	}
	return 0;
}