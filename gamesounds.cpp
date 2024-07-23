#include "gamesounds.h"

GameSounds::GameSounds() {}

void GameSounds::playBGMusic()
{
    bgMusic = new QMediaPlayer();
    QAudioOutput* audioOutput = new QAudioOutput;
    bgMusic->setAudioOutput(audioOutput);
    bgMusic->setSource(QUrl("qrc:/sounds/bgSound.mp3"));
    bgMusic->play();
}

void GameSounds::playVictoryMusic()
{
    victoryMusic= new QMediaPlayer();
    QAudioOutput* audioOutput = new QAudioOutput;
    victoryMusic->setAudioOutput(audioOutput);
    victoryMusic->setSource(QUrl("qrc:/sounds/winSound.wav"));
    victoryMusic->play();
}

void GameSounds::playDefeatMusic()
{
   defeatMusic= new QMediaPlayer();
    QAudioOutput* audioOutput = new QAudioOutput;
    defeatMusic->setAudioOutput(audioOutput);
    defeatMusic->setSource(QUrl("qrc:/sounds/loseSound.wav"));
    defeatMusic->play();
}

void GameSounds::playMoveMusic()
{
    moveMusic= new QMediaPlayer();
    QAudioOutput* audioOutput = new QAudioOutput;
    moveMusic->setAudioOutput(audioOutput);
    moveMusic->setSource(QUrl("qrc:/sounds/move.wav"));
    moveMusic->play();
}

void GameSounds::stopBGMusic()
{
    bgMusic->stop();
}

void GameSounds::stopVictoryMusic()
{
    victoryMusic->stop();
}

void GameSounds::stopDefeatMusic()
{
    defeatMusic->stop();
}

void GameSounds::stopMoveMusic()
{
    moveMusic->stop();
}


