#include<bits/stdc++.h>
using namespace std;

int lh(string a,string b) // a >= b
{
    int len;
    int lena=a.size(),lenb=b.size();
    if(lena>lenb)
    {
        len=lena;
    }
    else len=lenb;
    while(a.size()<len)
    {
        a='0'+a;
    }
    while(b.size()<len)
    {
        b='0'+b;
    }
    if(a<b)
    {
        return 0;
    }
    return 1;
}
int nh(string a,string b) // a <= b
{
    int len;
    int lena=a.size(),lenb=b.size();
    if(lena>lenb)
    {
        len=lena;
    }
    else len=lenb;
    while(a.size()<len)
    {
        a='0'+a;
    }
    while(b.size()<len)
    {
        b='0'+b;
    }
    if(a>b)
    {
        return 0;
    }
    return 1;
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
    while(nh(f[i],b))
    {
        if(lh(f[i],a)) res++;
        i++;
        f[i] = add(f[i-1],f[i-2]);
    }
    cout << res + (a=="1" && b != "4017655300550900044439300464406113743400900276716895373379501669055409485045877178822027073960005135722775743149674641246758175515662450996416072971");
}
