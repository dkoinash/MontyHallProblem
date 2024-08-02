#include <random> // std::uniform_int_distribution
#include <secret.h>
#include <tuple>

#define MIN 1
#define MAX 3
#define SUMM 1 + 2 + 3

int
Secret::randCell()
{
  auto rnd = []() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(MIN, MAX);

    return distrib(gen);
  };

  return rnd();
}

void
Secret::Start()
{
  m_prizeCell = randCell();
}

bool
Secret::Test(int cellNumber, bool isChange)
{
  /// Получение номера ячейки без выигрыша:
  auto rnd = [=]() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(MIN, MAX);

    int openCell;
    do
      openCell = distrib(gen);
    while (openCell == m_prizeCell && openCell != cellNumber);

    return openCell;
  };

  int emptyCell = rnd();

  if (!isChange) return cellNumber == m_prizeCell;

  int newCell = SUMM - cellNumber - emptyCell;

  return newCell == m_prizeCell;
}
