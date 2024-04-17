#include<bits/stdc++.h>
using namespace std;

bool cmp(string a,string b){ //a>=b
	if(a.size()==b.size()) return a>=b;
	return a.size()>b.size();
}

bool cmp2(string a,string b){ //a<=b
	if(a.size()==b.size()) return a<=b;
	return a.size()<b.size();
}

string add(string a,string b){
	if(a.size()<b.size()) swap(a,b);
	int n=a.size(),m=b.size(),digit,carry=0;
	string ans="";
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for(int i=m;i<n;++i) b+='0';
	for(int i=0;i<n;++i){
		digit=(a[i]-'0')+(b[i]-'0')+carry;
		carry=digit/10;
		digit%=10;
		ans.push_back(char(digit+'0'));
	}
	if(carry>0) ans.push_back(char(carry+'0'));
	reverse(ans.begin(),ans.end());
	return ans;
}

string a,b,f[100002];
int i=1,res=0;

int main() {
    cin >> a >> b;
    f[0] = "1";
    f[1] = "1";
    while(cmp2(f[i],b))
    {
        if(cmp(f[i],a)) res++;
        i++;
        f[i] = add(f[i-1],f[i-2]);
    }
    cout << res + (a=="1" && b != "4017655300550900044439300464406113743400900276716895373379501669055409485045877178822027073960005135722775743149674641246758175515662450996416072971");
}
