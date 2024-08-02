#pragma once

class Secret
{
private:
  /// Номер ячейки с призом
  int m_prizeCell;

public:
  /**
   * @brief Конструктор
   */
  Secret() = default;

  /**
   * @brief Деструктор
   */
  ~Secret() = default;

  /**
   * @brief Генерация случайного номера ячейки
   *
   * @return Возвращает номер ячейки
   */
  int randCell();

  /**
   * @brief Запуск (инициализация секрета)
   */
  void Start();

  /**
   * @brief Розыгрыш
   *
   * @param[in] cellNumber    Номер выбранной ячейки (1..3)
   * @param[in] isChange Признак смены ячейки после открытия одной не выигрышной ячейки
   * @return Возвращает true если угадал номер ячейки и false в противном случае
   */
  bool Test(int cellNumber, bool isChange = false);
};