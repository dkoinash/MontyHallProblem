#include <iostream>
#include <secret.h>

void
Test(size_t count)
{
  Secret game;
  int gameWinBase = 0;
  int gameWinIfChange = 0;
  for (int i = 0; i < count; ++i) {
    game.Start();
    bool res = game.Test(game.randCell());
    gameWinIfChange += !res;
    gameWinBase += res;
  }

  std::cout << "Сыграно: " << count << " раз, выиграно: " << gameWinBase
            << " раз, и если сменить ячейку выиграно: " << gameWinIfChange << std::endl;
  std::cout << "Вероятность выигрыша без смены ячейки: " << float(gameWinBase) / float(count) * 100
            << "% \nВероятность выигрыша со сменой ячейки: "
            << float(gameWinIfChange) / float(count) * 100 << "%" << std::endl;
}

int
main()
{
  int gameCount = 100000;
  Test(gameCount);

  return 0;
}
