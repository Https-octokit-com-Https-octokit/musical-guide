// Copyright 2019 The MWC Developers
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef H_HODLCOLD_W_H
#define H_HODLCOLD_W_H

#include "../core/navwnd.h"
#include "../wallet/wallet.h"

namespace Ui {
class HodlCold;
}

namespace state {
    class Hodl;
}

namespace wnd {

class HodlCold : public core::NavWnd
{
    Q_OBJECT

public:
    explicit HodlCold(QWidget *parent, state::Hodl * state);
    ~HodlCold();

    void setRootPubKeyWithSignature(const QString & key, const QString & message, const QString & signature);

    void reportMessage(const QString & title, const QString & message);
    void hideWaitingStatus();

private slots:
    void on_sign_clicked();

    void on_message_textChanged(const QString &arg1);

private:
    Ui::HodlCold *ui;
    state::Hodl * state;
};

}

#endif // H_HODLCOLD_W_H
