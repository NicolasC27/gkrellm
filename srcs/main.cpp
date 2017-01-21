#include <QApplication>
#include <QPushButton>
#include <QProgressBar>
#include "includes/modules/Date.hpp"

int main(int argc, char *argv[])

{
  Date dateuhh;
    QApplication app(argc, argv);

 

    QPushButton bouton("Salut les Zéros, la forme ?");

    bouton.show();

 

    return app.exec();

}
