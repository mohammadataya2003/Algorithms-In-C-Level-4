#include <iostream>
#include <string>
using namespace std;

long long ReadNumber()
{
	long long Number = 0;
	cout << "Enter a Number ";
	cin >> Number;
	return Number;
}

string ConvertNumberOneToText(string Number)
{
	if (Number == "1") return "One";
	else if (Number == "2") return "Two";
	else if (Number == "3") return "Three";
	else if (Number == "4") return "Four";
	else if (Number == "5") return "Five";
	else if (Number == "6") return "Six";
	else if (Number == "7") return "Seven";
	else if (Number == "8") return "Eight";
	else if (Number == "9") return "Nine";
	else return "";
}
string ConvertNumberTensToText(string Number)
{
	if (Number == "10") return "Ten";
	else if (Number == "11") return "Eleven";
	else if (Number == "12") return "Twelve"; 
	else if (Number == "13") return "Thirteen";
	else if (Number == "14") return "Fourteen";
	else if (Number == "15") return "Fifteen";
	else if (Number == "16") return "Sixteen";
	else if (Number == "17") return "Seventeen";
	else if (Number == "18") return "Eighteen";
	else if (Number == "19") return "Nineteen";

	return ""; 
}
string ConvertNumberDecadeToText(string Number)
{
	if (Number == "10") return "Ten";
	else if (Number == "2") return "Twenty";
	else if (Number == "3") return "Thirty";
	else if (Number == "4") return "Forty";
	else if (Number == "5") return "Fifty";
	else if (Number == "6") return "Sixty";
	else if (Number == "7") return "Seventy";
	else if (Number == "8") return "Eighty";
	else if (Number == "9") return "Ninety";

	return ""; 
}
string CorrectNumbers(long long  Number)
{
	string stNumber = to_string(Number);
	if (stNumber.length() % 3 == 1 )
	{
		return "00" + stNumber;
	}
	else if (stNumber.length() % 3 == 2)
	{
		return "0" + stNumber;
	}
	else {
		return  stNumber;
	}
}

void ConvertNumberToText(string stNumber, short stNumberLength)
{
	if (stNumberLength == 0) return;

	string chunk = stNumber.substr(0, 3);

	if (chunk != "000")
	{
		if (chunk[0] != '0') {
			cout << ConvertNumberOneToText(string(1, chunk[0])) << " Hundred ";
		}
		if (chunk[1] == '1') {
			cout << ConvertNumberTensToText(string(1, chunk[1]) + string(1, chunk[2])) << " ";
		}
		else {
			if (chunk[1] != '0') {
				cout << ConvertNumberDecadeToText(string(1, chunk[1])) << " ";
			}
			if (chunk[2] != '0') {
				cout << ConvertNumberOneToText(string(1, chunk[2])) << " ";
			}
		}
		if (stNumberLength > 9) cout << "Billion ";
		else if (stNumberLength > 6) cout << "Million ";
		else if (stNumberLength > 3) cout << "Thousand ";
	}
	if (stNumberLength > 3) {
		ConvertNumberToText(stNumber.substr(3), stNumberLength - 3);
	}
}

int main()
{
	long long Number = ReadNumber();
	if (Number == 0)
	{
		cout << "Zero" << endl;
	}
	else {
		string CorrectedNumber = CorrectNumbers(Number);
		ConvertNumberToText(CorrectedNumber, CorrectedNumber.length());
	}
	system("pause>0");
	
	return 0;
}



