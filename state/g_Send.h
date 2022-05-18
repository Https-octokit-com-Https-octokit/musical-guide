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

#ifndef MWC_QT_WALLET_SEND_H
#define MWC_QT_WALLET_SEND_H

#include "state.h"
#include "../wallet/wallet.h"
#include "../core/appcontext.h"
#include "../util/address.h"
#include <QSet>

namespace state {

QString generateAmountErrorMsg(int64_t mwcAmount, const wallet::AccountInfo &acc, const core::SendCoinsParams &sendParams);

class Send  : public QObject, public State {
    Q_OBJECT
public:
    Send( StateContext * context);
    virtual ~Send() override;

    bool isNodeHealthy() const {return nodeIsHealthy;}

    // Process sept 1 send request.  sendAmount is a value as user input it
    // return code:
    //   0 - ok
    //   1 - account error
    //   2 - amount error
    int initialSendSelection( bool isOnlineSelected, QString account, QString sendAmount );

    // Request for MWC to send
    void sendMwcOnline( const wallet::AccountInfo & account, util::ADDRESS_TYPE type, QString address, int64_t mwcNano,
            QString message, QString apiSecret, const QStringList & outputs, int changeOutputs, bool fluff );

    // Handle whole workflow to send offline
    // return true if some long process was started.
    bool sendMwcOffline( QString account, int64_t amount, QString message);

    // Handle whole workflow to send online
    // return true if some long process was started.
    bool sendMwcOnline( QString account, int64_t amount, QString address, QString apiSecret, QString message);

protected:
    virtual NextStateRespond execute() override;
    virtual QString getHelpDocName() override {return "send.html";}

private slots:
    void sendRespond( bool success, QStringList errors, QString address, int64_t txid, QString slate );

    void respSendFile( bool success, QStringList errors, QString fileName );

    void onNodeStatus( bool online, QString errMsg, int nodeHeight, int peerHeight, int64_t totalDifficulty, int connections );

private:
    void switchToStartingWindow();
private:
    bool nodeIsHealthy = false;
};

}

#endif
