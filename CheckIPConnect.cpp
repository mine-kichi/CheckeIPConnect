#include <afxsock.h> // MFC socket extensions

int main()
{
    AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0);

    if (!AfxSocketInit()) {
        std::cout << "Failed to Initialize Sockets" << std::endl;
        return 1;
    }

    CSocket socket;
    if (!socket.Create()) {
        std::cout << "Failed to Create Socket" << std::endl;
        return 1;
    }

    // 例としてGoogle Public DNS(8.8.8.8)への接続を試みています。
    if (!socket.Connect(_T("8.8.8.8"), 80)) { // 例としてポート80を使用しています。
        std::cout << "Failed to Connect" << std::endl;
        return 1;
    }

    std::cout << "Connected" << std::endl;

    socket.Close();

    return 0;
}
