#include "MMPlay.h"
#include "ui_MMPlay.h"
#include <QBoxLayout>
#include <qdebug.h>

MMPlayClass::MMPlayClass(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MMPlayClass),
	m_playerState(QMediaPlayer::StoppedState)
{
	ui->setupUi(this);

	//MainWindow�Դ�layout��������Ҫ�Զ���layout���������ó�����layout
	//���򽫻���ֲ�������layout����
	QWidget *widget = new QWidget;
	this->setCentralWidget(widget);

	player = new QMediaPlayer();

	Playlist = new QMediaPlaylist();
	player->setPlaylist(Playlist);

	videoWidget = new QVideoWidget(widget);
	player->setVideoOutput(videoWidget);
	ui->progressBar->setRange(0, player->duration() / 1000);

	//ˮƽ���֣����ư�ť
	QBoxLayout *ctlLayout = new QHBoxLayout;
	ctlLayout->addWidget(ui->openFileBtn);
	ctlLayout->addWidget(ui->playBtn);
	ctlLayout->addWidget(ui->stopBtn);
	ctlLayout->addWidget(ui->fullScrBtn);

	//��ֱ���֣���Ƶ�������������������ư�ť����
	QBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addWidget(videoWidget);
	mainLayout->addWidget(ui->progressBar);
	mainLayout->addLayout(ctlLayout);

	//���ò���
	widget->setLayout(mainLayout);


	//�źŲ�
	QObject::connect(ui->openFileBtn, SIGNAL(clicked()), this, SLOT(openFile()));
	QObject::connect(ui->playBtn, SIGNAL(clicked()), this, SLOT(playVideo()));
	QObject::connect(ui->stopBtn, SIGNAL(clicked()), this, SLOT(stopVideo()));
	QObject::connect(ui->fullScrBtn, SIGNAL(clicked()), this, SLOT(fullScr()));
}

MMPlayClass::~MMPlayClass()
{
	delete ui;
}

void MMPlayClass::openFile()
{
	QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open Files"), "e:workspace", tr("Media(*.mp4 *.*"));
	addToPlaylist(fileNames);
}

void MMPlayClass::playVideo()
{
	m_playerState = QMediaPlayer::PlayingState;
	player->play();
}

void MMPlayClass::stopVideo()
{
	m_playerState = QMediaPlayer::StoppedState;
	player->stop();
}

void MMPlayClass::fullScr()
{
	if (m_playerState == QMediaPlayer::PlayingState)
	{
		videoWidget->setFullScreen(true);
	}
	else
	{
		videoWidget->setFullScreen(false);
	}

}

//�˳�ȫ��
void MMPlayClass::keyPressEvent(QKeyEvent *event) {
	if (event->key() == Qt::Key_Escape) {
		this->videoWidget->setFullScreen(false);
	}
}

void MMPlayClass::addToPlaylist(const QStringList& fileNames)
{
	foreach(QString const &argument, fileNames) {
		QFileInfo fileInfo(argument);
		if (fileInfo.exists()) {
			QUrl url = QUrl::fromLocalFile(fileInfo.absoluteFilePath());
			qDebug() << "current choese" << url;
			if (fileInfo.suffix().toLower() == QLatin1String("m3u")) {
				Playlist->load(url);
			}
			else
				Playlist->addMedia(url);
			//Playlist->next();
		}
		else {
			QUrl url(argument);
			if (url.isValid()) {
				Playlist->addMedia(url);
			}
		}

	}
}
