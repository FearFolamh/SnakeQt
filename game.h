#ifndef GAME_H
#define GAME_H

#include <QPainter>
#include <QWidget>
#include <QList>
#include <QTimer>
#include <QKeyEvent>
#include <QRandomGenerator>


class SnakeItem;
class Snake;
class GameField;

class SnakeItem{
    friend Snake;
    friend GameField;
public:
    SnakeItem(int x,int y);
private:
    int m_x;
    int m_y;
};

class Snake{
    friend GameField;
public:
    Snake();
private:
    QList<SnakeItem*> m_snakeBody;
    int m_snakeBeginSize;
    enum SnakeDirection
    {
        up,
        left,
        down,
        right

    };
    SnakeDirection m_snakeDirection;
};

class GameField:public QWidget
{
    Q_OBJECT
public:
    GameField();
protected:
    void paintEvent(QPaintEvent *e) override;
    void keyPressEvent(QKeyEvent *e) override;
private:
    Snake *m_snake;
    int m_snakeItemSize;
    QTimer *m_moveSnakeTimer;
    int m_fieldSize;
    SnakeItem *m_food;
    int m_score;
    bool m_isPause;
    bool m_isMoveBlocked;
    bool m_isGameOver;
    void GameOver();
    void StartNewGame();
    void SetGameStatus();
    void CreateFood();

private slots:
    void MoveSnakeSlot();
signals:
    void ChangeTextSignal(QString text);
};

#endif // GAME_H
