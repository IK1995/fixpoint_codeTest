#include<iostream>
#include<vector>
#include<algorithm>
#include <string>
#include <map>
#include<cstring>
#include <fstream>   // ifstream, ofstream
#include <sstream>   // istringstream
using namespace std;
typedef long long ll;
const int mod = 1000000007;

typedef pair<string,ll> A;

int main(){
  string filename = "filename.txt";
  ifstream ifs(filename);
  int mode;
  cout<<"期間を指定しますか？Yes:1 No:0 ::";
  cin>>mode;
  cout<<endl;
  string sy,ey;
  int sd;
  int ed;
  if(mode){
    cout<<"期間のはじめはいつですか？yyyy/mm/ddで入力 ::";
    cin>>sy;
    cout<<"期間の終わりはいつですか？yyyy/mm/ddで入力 ::";
    cin>>ey;
    sd=(sy[0]-'0')*10000000+(sy[1]-'0')*1000000+(sy[2]-'0')*100000+(sy[3]-'0')*10000
       +(sy[5]-'0')*1000+(sy[6]-'0')*100+(sy[8]-'0')*10+(sy[9]-'0');
    ed=(ey[0]-'0')*10000000+(ey[1]-'0')*1000000+(ey[2]-'0')*100000+(ey[3]-'0')*10000
       +(ey[5]-'0')*1000+(ey[6]-'0')*100+(ey[8]-'0')*10+(ey[9]-'0');
  }
  map<string, ll> timec;
  map<string, ll> lhostc;
  //fn.open(filename, std::ios::in);
  string file ;
  while(getline(ifs,file)){
    ifstream rf(file);
    //rf.open(file, ios::in);
    string log;
    while(getline(rf,log)){
      auto separator = string(" ");
      auto list = vector<std::string>();
      auto offset = string::size_type(0);
      while (1) {
        auto pos = log.find(separator, offset);
        if (pos == string::npos) {
          list.push_back(log.substr(offset));
          break;
        }
        list.push_back(log.substr(offset, pos - offset));
        offset = pos + 1;
      }

      if(mode){
        char m[3];
        m[0]=list[3][4];
        m[1]=list[3][5];
        m[2]=list[3][6];
        int d=(list[3][8]-'0')*10000000+(list[3][9]-'0')*1000000+(list[3][10]-'0')*100000+(list[3][11]-'0')*10000
              +(list[3][1]-'0')*10+(list[3][2]-'0');
        if(!strcmp(m,"Jan")) d+=100;
        else if(!strcmp(m,"Feb")) d+=200;
        else if(!strcmp(m,"Mar")) d+=300;
        else if(!strcmp(m,"Apr")) d+=400;
        else if(!strcmp(m,"May")) d+=500;
        else if(!strcmp(m,"Jun")) d+=600;
        else if(!strcmp(m,"Jul")) d+=700;
        else if(!strcmp(m,"Aug")) d+=800;
        else if(!strcmp(m,"Sep")) d+=900;
        else if(!strcmp(m,"Oct")) d+=1000;
        else if(!strcmp(m,"Nov")) d+=1100;
        else if(!strcmp(m,"Dec")) d+=1200;
        if(d >= sd && d <= ed){
          lhostc[list[0]]++;
          timec[list[3]]++;
        }
      }else{
        //ここでリストには空白文字で分割されたやつが入っている
        //リモートホスト別カウント
        lhostc[list[0]]++;
        //時間帯別カウント
        //時間帯＝dd/mm/yyyy:hh/mm/ss 別と考えるときをメインで書く
        timec[list[3]]++;
      }
    }
  }
  vector<A> ans;
  for(auto itr = lhostc.begin(); itr != lhostc.end(); ++itr) {
        ans.push_back(make_pair(itr->first,itr->second));
    }
  sort(ans.begin(),ans.end(),[](const A& x,const A& y){
    return x.second>y.second;
  });

  cout<<"各時間帯ごとのアクセス件数"<<endl;
  if(timec.size()){
    for(auto itr = timec.begin(); itr != timec.end(); ++itr) {
          cout<<"時間帯: "<<itr->first<<" 件数: "<<itr->second<<endl;
      }
  }else{
    cout<<"存在しません"<<endl;
  }
  cout<<"リモートホスト別のアクセス件数"<<endl;
  if(lhostc.size()){
    for(int i=0;i<ans.size();i++){
      cout<<"ローカルホスト: "<<ans[i].first<<" 件数: "<<ans[i].second<<endl;
    }
  }else{
    cout<<"存在しません"<<endl;
  }
  return 0;
}
