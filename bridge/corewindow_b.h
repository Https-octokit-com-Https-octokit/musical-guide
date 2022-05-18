// Copyright 2020 The MWC Developers
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

#ifndef MWC_QT_WALLET_COREWINDOW_B_H
#define MWC_QT_WALLET_COREWINDOW_B_H

#include <QObject>
#include "../state/statemachine.h"

namespace bridge {

// WindowManager need it's own bridge
class CoreWindow : public QObject {
Q_OBJECT
public:
    explicit CoreWindow(QObject * parent = nullptr);
    ~CoreWindow();

    // Window manager
    void setDataPath(const QString& dataPath);

    // Main Window
    void updateActionStates(state::STATE actionState);

signals:
    // This
    void sgnSetDataPath(QString dataPath);
    void sgnUpdateActionStates(int actionState); // state::STATE values
protected:
};

}

#endif //MWC_QT_WALLET_COREWINDOW_B_H
