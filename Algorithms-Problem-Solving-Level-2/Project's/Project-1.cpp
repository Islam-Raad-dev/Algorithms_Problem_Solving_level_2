/*
================================================================================
                          (Stone, Paper, Scissors)
================================================================================
وصف المشروع:
هذا البرنامج عبارة عن محاكاة للعبة الكلاسيكية "حجر، ورقة، مقص" ضد الكمبيوتر.

مميزات اللعبة:
- مرونة الجولات: يمكن للاعب اختيار عدد الجولات التي يرغب بلعبها في المباراة الواحدة.
- ذكاء اصطناعي بسيط: يقوم الكمبيوتر باختيار حركته بشكل عشوائي بالكامل.
- نظام تحكيم دقيق: يحدد الفائز في كل جولة، والفائز النهائي بعد انتهاء كل الجولات.
- واجهة ملونة تفاعلية: 
  * اللون الأخضر: عند فوز اللاعب.
  * اللون الأحمر (مع رنة تنبيه): عند فوز الكمبيوتر.
  * اللون الأصفر: عند التعادل.
  
================================================================================
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// تعريف خيارات اللعبة
enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };

// تعريف الفائزين المحتملين
enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

// هيكل لحفظ معلومات الجولة الواحدة
struct stRoundInfo {
    short RoundNumber = 0;
    enGameChoice Player1Choice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string WinnerName;
};

// هيكل لحفظ النتيجة النهائية للمباراة
struct stGameResults {
    short GameRounds = 0;
    short Player1WinTimes = 0;
    short ComputerWinTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner;
    string WinnerName = "";
};

// دالة لتوليد رقم عشوائي (لاختيارات الكمبيوتر)
int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

// دالة لتنظيف الشاشة وإعادة اللون الافتراضي (مخصصة لبيئة لينكس)
void ClearScreen() {
    system("clear");
    cout << "\033[0m"; 
}

// دالة لتغيير لون النص بناءً على الفائز (مخصصة لبيئة لينكس)
void SetScreenColor(enWinner Winner) {
    if (Winner == enWinner::Player1) {
        cout << "\033[32m"; // لون أخضر لفوز اللاعب
    } 
    else if (Winner == enWinner::Computer) {
        cout << "\033[31m"; // لون أحمر لفوز الكمبيوتر
        cout << "\a";       // صوت تنبيه (Beep)
    } 
    else {
        cout << "\033[33m"; // لون أصفر للتعادل
    }
}

// دالة لقراءة عدد الجولات من اللاعب
short ReadHowManyRounds() {
    short GameRounds = 1;
    do {
        cout << "\nHow Many Rounds Do You Want To Play? ";
        cin >> GameRounds;
    } while (GameRounds <= 0);
    return GameRounds;
}

// دالة لقراءة اختيار اللاعب
enGameChoice ReadPlayer1Choice() {
    short Choice;
    do {
        cout << "\nYour Choice: [1] Stone, [2] Paper, [3] Scissors ? ";
        cin >> Choice;
    } while (Choice < 1 || Choice > 3);
    return (enGameChoice)Choice;
}

// دالة للحصول على اختيار الكمبيوتر (عشوائي)
enGameChoice GetComputerChoice() {
    return (enGameChoice)RandomNumber(1, 3);
}

// دالة لتحديد الفائز في الجولة
enWinner WhoWonTheRound(stRoundInfo RoundInfo) {
    if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
        return enWinner::Draw;

    switch (RoundInfo.Player1Choice) {
        case enGameChoice::Stone:
            return (RoundInfo.ComputerChoice == enGameChoice::Paper) ? enWinner::Computer : enWinner::Player1;
        case enGameChoice::Paper:
            return (RoundInfo.ComputerChoice == enGameChoice::Scissors) ? enWinner::Computer : enWinner::Player1;
        case enGameChoice::Scissors:
            return (RoundInfo.ComputerChoice == enGameChoice::Stone) ? enWinner::Computer : enWinner::Player1;
    }
    return enWinner::Draw;
}

// دالة لتحديد الفائز النهائي باللعبة
enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes) {
    if (Player1WinTimes > ComputerWinTimes)
        return enWinner::Player1;
    else if (ComputerWinTimes > Player1WinTimes)
        return enWinner::Computer;
    else
        return enWinner::Draw;
}

// دالة لتحويل خيار اللعبة إلى نص للطباعة
string ChoiceName(enGameChoice Choice) {
    string arrGameChoices[3] = {"Stone", "Paper", "Scissors"};
    return arrGameChoices[Choice - 1];
}

// دالة لتحويل الفائز إلى نص للطباعة
string WinnerName(enWinner Winner) {
    string arrWinnerName[3] = {"Player1", "Computer", "Draw"};
    return arrWinnerName[Winner - 1];
}

// دالة لطباعة نتيجة الجولة الواحدة
void PrintRoundResults(stRoundInfo RoundInfo) {
    SetScreenColor(RoundInfo.Winner); // تلوين الشاشة بناءً على الفائز
    cout << "\n\t============== Round [" << RoundInfo.RoundNumber << "] ==============\n\n";
    cout << "\tPlayer1 Choice : " << ChoiceName(RoundInfo.Player1Choice) << endl;
    cout << "\tComputer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
    cout << "\tRound Winner   : [" << RoundInfo.WinnerName << "]\n";
    cout << "\t========================================\n" << endl;
    cout << "\033[0m"; // إعادة اللون الافتراضي بعد طباعة الجولة
}

// دالة لعرض عنوان نهاية اللعبة
void ShowGameOverScreen() {
    cout << "\n\t\t__________________________________________________________\n\n";
    cout << "\t\t\t\t+++ G A M E  O V E R +++\n";
    cout << "\t\t__________________________________________________________\n\n";
}

// دالة لطباعة النتيجة النهائية للعبة
void ShowFinalGameResults(stGameResults GameResults) {
    SetScreenColor(GameResults.GameWinner); // تلوين النتيجة النهائية
    cout << "\t\t[Game Results]\n\n";
    cout << "\t\tGame Rounds        : " << GameResults.GameRounds << endl;
    cout << "\t\tPlayer1 Won Times  : " << GameResults.Player1WinTimes << endl;
    cout << "\t\tComputer Won Times : " << GameResults.ComputerWinTimes << endl;
    cout << "\t\tDraw Times         : " << GameResults.DrawTimes << endl;
    cout << "\t\tFinal Winner       : " << GameResults.WinnerName << endl;
    cout << "\t\t__________________________________________________________\n";
    cout << "\033[0m"; // إعادة اللون الافتراضي
}

// دالة التحكم الرئيسية بسير اللعبة
stGameResults PlayGame(short HowManyRounds) {
    stRoundInfo RoundInfo;
    short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

    for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++) {
        cout << "\nRound [" << GameRound << "] begins:\n";
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.Player1Choice = ReadPlayer1Choice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.Winner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

        // حساب عدد مرات الفوز
        if (RoundInfo.Winner == enWinner::Player1)
            Player1WinTimes++;
        else if (RoundInfo.Winner == enWinner::Computer)
            ComputerWinTimes++;
        else
            DrawTimes++;

        PrintRoundResults(RoundInfo);
    }

    // تعبئة هيكل النتيجة النهائية وإرجاعه
    stGameResults GameResults;
    GameResults.GameRounds = HowManyRounds;
    GameResults.Player1WinTimes = Player1WinTimes;
    GameResults.ComputerWinTimes = ComputerWinTimes;
    GameResults.DrawTimes = DrawTimes;
    GameResults.GameWinner = WhoWonTheGame(Player1WinTimes, ComputerWinTimes);
    GameResults.WinnerName = WinnerName(GameResults.GameWinner);

    return GameResults;
}

// دالة بدء اللعبة والسؤال عن الإعادة
void StartGame() {
    char PlayAgain = 'Y';
    do {
        ClearScreen(); // تنظيف الشاشة مع كل لعبة جديدة
        
        short Rounds = ReadHowManyRounds();
        stGameResults GameResults = PlayGame(Rounds);

        ShowGameOverScreen();
        ShowFinalGameResults(GameResults);

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

// نقطة البداية (Main)
int main() {
    // تهيئة مولد الأرقام العشوائية مرة واحدة فقط
    srand((unsigned)time(NULL));
    
    StartGame();
    
    return 0;
}
