#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {

  int command = 0;
  int treasure = 0;
  int count = 0;
  int random;
  srand(static_cast<unsigned int>(time(0)));

  cout << "**宝探しゲーム**\n\n";
  cout << "READ ME!!!\n";
  cout << "探索して宝を集めるゲームです\n十回探索するうちに宝を集めよう！";

  while (count < 10) {
    int randomNumber = rand();
    random = (randomNumber % 5) + 1;
    count++;
    cout << "１:探索\n";
    cout << "２:点数確認\n";
    cout << "\nコマンド？：";
    cin >> command;

    if (command == 1) {
      if (5 == random) {
        cout << "\nお宝発見！\n\n";
        treasure += 2;
        continue;
      } else if (4 == random) {
        cout << "盗賊襲来！\n\n";
        cout << "１:戦う\n";
        cout << "２:逃げる\n";
        cout << "\nコマンド？：";
        cin >> command;
        if (command == 1) {
          if (2 == (randomNumber % 2) + 1) {
            cout << "戦闘に勝利！宝を奪った！\n\n";
            treasure = treasure * 2;
            continue;
          } else {
            cout << "敗北した...宝を盗まれた...\n\n";
            treasure = treasure / 1.5;
            continue;
          }
        } else if (command == 2) {
          cout << "逃げ切った！\n\n";
          continue;
        }
      } else {
        cout << "\n何も見つからない...\n\n";
        continue;
      }
    } else if (command == 2) {
      cout << "\n" << treasure << "＄分の宝を集めています\n\n";
    }
  }
  cout << "\n\n\n結果発表！\n\n";
  cout << treasure << "＄分の宝を集めた！";
  return 0;
}