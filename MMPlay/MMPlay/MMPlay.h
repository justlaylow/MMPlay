//头文件
#ifndef MMPLAY_H
#define MMPLAY_H

#include <QMainWindow>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QMediaPlaylist>
#include <QKeyEvent>

namespace Ui {
	class MMPlayClass;
}

class MMPlayClass : public QMainWindow
{
	Q_OBJECT

public:
	explicit MMPlayClass(QWidget *parent = 0);
	~MMPlayClass();
	void addToPlaylist(const QStringList& fileNames);
private:
	Ui::MMPlayClass *ui;
	QMediaPlayer *player;
	QVideoWidget *videoWidget;
	QMediaPlaylist *Playlist;
	QString m_fileName;
	QMediaPlayer::State  m_playerState;

private slots:
	void openFile();
	void playVideo();
	void stopVideo();
	void fullScr();
	//监听键盘 退出全屏
	void keyPressEvent(QKeyEvent *event);
};

#endif // MMPLAY_H
