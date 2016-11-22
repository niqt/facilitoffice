#include "dialog_configuration.h"

#include "ui_dialog_configuration.h"

#include <QtWidgets/QColorDialog>

DialogConfiguration::DialogConfiguration(QWidget *parent)
    : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->reimpostaPushButton, SIGNAL(clicked()), this, SLOT(reimposta()));
    connect(ui->colorePushButton, SIGNAL(clicked()), this, SLOT(chooseColor()));
}

Configurations DialogConfiguration::getConfigurations(Configurations old, bool &ok)
{
    Configurations newConfigurations;

    ok = false;

    ui->tabWidget->setCurrentIndex(0);
    // Set old value

    ui->eliminaScelteCheckBox->setChecked(false);
    ui->eliminaQuaderniCheckBox->setChecked(false);

    if(old.voice == "Maschio")
        ui->voiceComboBox->setCurrentIndex(0);
    else
       ui->voiceComboBox->setCurrentIndex(1);

    ui->speedHorizontalSlider->setValue(old.speed);
    ui->volumeHorizontalSlider->setValue(old.volume);
    ui->evidenziaCheckBox->setChecked(old.evidence);
    ui->mantieniCheckBox->setChecked(old.showEvidence);
    if(old.evidenceType == 1)
        ui->evidenziaRadioButton->setChecked(true);
    else if(old.evidenceType == 0)
        ui->modificaRadioButton->setChecked(true);
    else
        ui->sottolineaRadioButton->setChecked(true);
    ui->letturaCheckBox->setChecked(old.readText);
    ui->evidenziaRigaCheckBox->setChecked(old.evidenceRow);
    ui->scelteCheckBox->setChecked(old.shortcuts);
    ui->quaderniCheckBox->setChecked(old.copybooks);

    color = old.color;

    QDialog::exec();

    if((ok = okPushed))
    {
        newConfigurations.evidenceType = 2;

        newConfigurations.color = color;
        newConfigurations.voice = ui->voiceComboBox->currentText();
        newConfigurations.speed = ui->speedHorizontalSlider->value();
        newConfigurations.volume = ui->volumeHorizontalSlider->value();
        newConfigurations.evidence = ui->evidenziaCheckBox->isChecked();
        newConfigurations.showEvidence = ui->mantieniCheckBox->isChecked();
        newConfigurations.readText = ui->letturaCheckBox->isChecked();
        newConfigurations.evidenceRow = ui->evidenziaRigaCheckBox->isChecked();
        newConfigurations.shortcuts = ui->scelteCheckBox->isChecked();
        newConfigurations.copybooks = ui->quaderniCheckBox->isChecked();

        if(ui->evidenziaRadioButton->isChecked())
            newConfigurations.evidenceType = 1;
        else if(ui->modificaRadioButton->isChecked())
            newConfigurations.evidenceType = 0;




    }

    return newConfigurations;
}

void DialogConfiguration::reject()
{
    okPushed = false;
    QDialog::reject();
}

void DialogConfiguration::accept()
{
    okPushed = true;
    QDialog::accept();
}

void DialogConfiguration::reimposta()
{
}

void DialogConfiguration::play()
{
}

void DialogConfiguration::chooseColor()
{
    QColor oldColor(color);
    color = (QColorDialog::getColor (oldColor)).rgb();
}
