#ifndef GAMESOUNDS_H
#define GAMESOUNDS_H
#include <QMediaPlayer>
#include <QAudioOutput>
class GameSounds
{
public:
    GameSounds();
     void playBGMusic();
     void playVictoryMusic();
     void playDefeatMusic();
     void playMoveMusic();

     void stopBGMusic();
     void stopVictoryMusic();
     void stopDefeatMusic();
     void stopMoveMusic();

private:
    QMediaPlayer *bgMusic;
    QMediaPlayer *victoryMusic;
    QMediaPlayer *defeatMusic;
    QMediaPlayer *moveMusic;
};

#endif // GAMESOUNDS_H
