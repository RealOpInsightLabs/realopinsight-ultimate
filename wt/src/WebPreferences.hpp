/*
 * WebSettingUI.hpp
# ------------------------------------------------------------------------ #
# Copyright (c) 2010-2013 Rodrigue Chakode (rodrigue.chakode@ngrt4n.com)   #
# Last Update : 29-12-2013                                                 #
#                                                                          #
# This file is part of RealOpInsight (http://RealOpInsight.com) authored   #
# by Rodrigue Chakode <rodrigue.chakode@gmail.com>                         #
#                                                                          #
# RealOpInsight is free software: you can redistribute it and/or modify    #
# it under the terms of the GNU General Public License as published by     #
# the Free Software Foundation, either version 3 of the License, or        #
# (at your option) any later version.                                      #
#                                                                          #
# The Software is distributed in the hope that it will be useful,          #
# but WITHOUT ANY WARRANTY; without even the implied warranty of           #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            #
# GNU General Public License for more details.                             #
#                                                                          #
# You should have received a copy of the GNU General Public License        #
# along with RealOpInsight.  If not, see <http://www.gnu.org/licenses/>.   #
#--------------------------------------------------------------------------#
 */

#ifndef WEBSESSION_HPP
#define WEBSESSION_HPP

#include "Preferences.hpp"
#include <Wt/WDialog>
#include <Wt/WRadioButton>
#include <Wt/WLineEdit>
#include <Wt/WComboBox>
#include <Wt/WPushButton>
#include <Wt/WSpinBox>
#include <Wt/WCheckBox>
#include <Wt/WObject>
#include <QVector>


class QString;

class WebPreferences : public Preferences, public Wt::WObject
{
public:
  WebPreferences(int _userRole);
  virtual ~WebPreferences();

  void show(void) {m_dialog->show();}
  void handleClose(void) {m_dialog->accept();}

protected :
  virtual void handleCancel(void);
  virtual void applyChanges(void);
  virtual QString letUserSelectType(void);
  virtual void addAsSource(void);
  virtual void deleteSource(void);
  virtual void fillFromSource(int _sidx);
  virtual void updateSourceBtnState(void);
  virtual void updateFields(void);
  virtual void saveAsSource(const qint32& _idx, const QString& _stype);

private:
  Wt::WDialog* m_dialog;
  Wt::WLineEdit* m_monitorUrlField;
  Wt::WLineEdit* m_authStringField;
  Wt::WLineEdit* m_livestatusAddressField;
  Wt::WComboBox* m_monitorTypeField;
  Wt::WCheckBox* m_clearAuthStringField;
  Wt::WCheckBox* m_useNgrt4ndField;
  Wt::WCheckBox* m_dontVerifyCertificateField;
  Wt::WSpinBox* m_updateIntervalField;
  Wt::WPushButton* m_cancelBtn;
  Wt::WPushButton* m_applyChangeBtn;
  Wt::WPushButton* m_addAsSourceBtn;
  Wt::WPushButton* m_deleteSourceBtn;
  Wt::WButtonGroup* m_srcBtnGroup;
};

#endif // WEBSESSION_HPP