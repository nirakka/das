#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

#include "globl.h"

// 文字列->内部表現

using namespace std;

// strの(b,e-1)を10進数で返す 数字以外なら-1 負の数は未対応
static int dec(const string& str, int b, int e)
{
	int v = 0;
	for (int i=b;i<e;i++) {
		char c = str[i];
		if (c < '0' || c > '9')
		return -1;
		v = v * 10 + (c-'0');
	}
	return v;
}

// うるう年は未対応(対応予定なし)
static int days[] = 
	{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// 日付:フォーマットエラーなら-1を返す(引数不変)
int parseDate(const string& str, Date& date)
{
	if (str.length() != 8) return -1;

	int y = dec(str,0,2);
	int m = dec(str,3,5);
	int d = dec(str,6,8);

	if (y<0 || y>99) return -1;
	if (m<1 || m>12) return -1;
	if (d<1 || d>days[m-1]) return -1;

	date = Date(y,m,d);
	return 0;
}

// 時刻:フォーマットエラーなら-1を返す(引数不変)
int parseTime(const string& str, Time& time)
{
	if (str.length() != 8) return -1;

	int h = dec(str,0,2);
	int m = dec(str,3,5);
	int s = dec(str,6,8);

	if (h<0 || h>23) return -1;
	if (m<0 || m>59) return -1;
	if (s<0 || s>59) return -1;

	time = Time(h,m,s);
	return 0;
}

// 収集条件:範囲外なら-1を返す
int parseCollection(const string& str, Collection& col)
{
	int len = str.length();
	int e = str.find_first_of("=",1);
	int n = dec(str,1,e);     // =の前まで
	int a = dec(str,e+1,len); // =の直後から最後まで

	if (n<1 || n>8) return -1;
	if (a<0 || a>9999) return -1;

	col = Collection(X(n),a); // str[0]でXかAか決まる
	return 0;
}

// 警告条件:範囲外なら-1を返す (2文字opは未対応:かなりの修正が必要)
int parseCondition(const string& str, int b, int e, Condition& cond)
{
	int op = str.find_first_of(">=<",b+1);
	int n = dec(str,b+1,op); // opの前まで
	int a = dec(str,op+1,e); // opの直後から最後まで

	if (n<1 || n>8) return -1;
	if (a<0 || a>9999) return -1;

	char c = str[e]; // cによりopが決定(未対応)
	
	cond = Condition(X(n),a,1); // str[b]でXかAか決まる
	return 0;
}

// 出力:範囲外なら-1を返す
int parseAction(const string& str, int b, int e, Action& act)
{
	int op = str.find_first_of("=",b+1);
	int n = dec(str,b+1,op); // =の前まで
	int a = dec(str,op+1,e); // =の直後から最後まで

	if (n<1 || n>8) return -1;
	if (a<0 || a>9999) return -1;

	act = Action(B(n),a); // str[b]でBかYか決まる
	return 0;
}

// 警告条件全体 :以下はオプション
int parseWarn(const string& str, Warn &wa)
{
	int r =0;
	int len = str.length();
	int colon = str.find_first_of(":");
	if (colon == string::npos)// コロンがなければ
		colon = len; // 最後にコロンがあるものとみなす
		
	r = parseCondition(str, 0, colon, *wa.cond); // 条件を変換
	if (r < 0) return -1;
	
	if (colon < len) { // コロンがあれば
		r = parseAction(str ,colon+1, len, *wa.act); // 出力を変換
		if (r < 0) return -1;
	}
	return 0;
}

//-----------------

void convDate(void)
{
	Date d(99,99,99);
	string str = "19-12-01";
	//string str = "19-12-40";

	cout << string(__FUNCTION__) << ":";
	if (parseDate(str,d)<0)
		cout << "error:";	
	cout << d.str() << endl;
}

void convTime(void)
{
	Time t(99,99,99);
	string str = "12:34:56";
	//string str = "12:34:78";

	cout << string(__FUNCTION__) << ":";
	if (parseTime(str,t)<0)
		cout << "error:";	
	cout << t.str() << endl;	
}

void convCollection(void)
{
	Collection col(99,9999);
	string str = "X1=1000";
	//string str = "X1=30000";
	
	cout << string(__FUNCTION__) << ":";
	if (parseCollection(str,col)<0)
		cout << "error:";	
	cout << col.str() << endl;	
}

void convCondition(void)
{
	Condition cond(99,9999,1);
	string str = "X1>3000";
	//string str = "X1>30000";

	cout << string(__FUNCTION__) << ":";
	if (parseCondition(str, 0, str.length(), cond)<0)
		cout << "error:";	
	cout << cond.str() << endl;	
}

void convAction(void)
{
	Action act(99,9999);
	string str = "B1=1";
	//string str = "B1=30000";

	cout << string(__FUNCTION__) << ":";
	if (parseAction(str, 0, str.length(), act)<0)
		cout << "error:";
	cout << act.str() << endl;	
}

void convWarn(void)
{
	static Condition cond(99,9999);
	static Action act(0,0);
	Warn wa(&cond,&act);
	
	string str = "X1>3000:B1=1";
	//string str = "X1>3000";
	
	cout << string(__FUNCTION__) << ":";
	if (parseWarn(str, wa)<0)
		cout << "error:";
	cout << wa.str() << endl;	
}

int main(void)
{
	convDate();
	convTime();
	convCollection();
	convCondition();
	convAction();
	convWarn();
}
