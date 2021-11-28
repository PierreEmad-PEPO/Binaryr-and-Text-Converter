#include<bits/stdc++.h>

using namespace std;

int asc=0,d=0;
int c=128,start=1;
fstream f,o;
string s="",b="";


void btot()
{

   o.open("text.txt",ios::out);
   f.open("binary.txt",ios::in);
   string t;
   getline(f,t);
   s+=t;
   t="";

    for(long long i=1;i<=s.size();i++)
    {
        if(i%8==0)
        {

            b=s.substr(start,8);
            start+=8;
            for(int j=0;j<8;j++)
            {
             if(b[j]=='1')
                    asc+=c;
             c/=2;
            }
            cout<<char(asc);
            o<<char(asc);
            asc=0;
            c=128;
        }

    }
    o.flush();
}

void ttob()
{

    o.open("binary.txt",ios::out);
   f.open("text.txt",ios::in);
     string t;
   getline(f,t);
   s+=t;
   t="";


    for(long long i=1;i<s.size();i++)
    {
        string bin="";
      d=int(s[i]);
       for(int g=0;g<8;g++)
       {
          bin+=char((d%2)+'0');
           d/=2;
       }
        reverse(&bin[0],&bin[8]);
        cout<<bin;
        o<<bin;


    }

o.flush();
}

int main()
{
    s+='"';
    int inp;
    cout<<"--------------------------------------------\n";
    cout<<"\n1.Text to Binary\t2.Binary to Text\n\n";
    cout<<"--------------------------------------------\n";
    cin>>inp;
    switch(inp)
    {
        case 1:
        ttob();
        break;
        case 2:
        btot();
        break;
    }

    return 0;
}
