    QTime *timeLap = new QTime(0,0,0);
    Welcome to Git (version 1.9.5-preview20150319)


Run 'git help git' to display the help index.
Run 'git help <command>' to display help for specific commands.

coca@COCA-PC ~
$ cd C:

coca@COCA-PC /c
$ s
sh.exe": s: command not found

coca@COCA-PC /c
$ ls
$Recycle.Bin            HPFWUpdate.log       Qt                         cygwin64       eula.3082.txt         install.res.1040.dll  uninstall.exe
ATP                     Intel                QtEnterPrise               eula.1028.txt  globdata.ini          install.res.1041.dll  uninstall.ini
Archivos de programa    MinGW                Recovery                   eula.1031.txt  hiberfil.sys          install.res.1042.dll  vcredist.bmp
CMAPS                   Nexon                System Volume Information  eula.1033.txt  install.exe           install.res.2052.dll  xampp
Config.Msi              PerfLogs             Users                      eula.1036.txt  install.ini           install.res.3082.dll
Desk                    Program Files        VC_RED.MSI                 eula.1040.txt  install.res.1028.dll  mingw-w64.bat
Documents and Settings  Program Files (x86)  VC_RED.cab                 eula.1041.txt  install.res.1031.dll  mingw-w64.url
ExeLed                  ProgramData          Windows                    eula.1042.txt  install.res.1033.dll  msdia80.dll
FixBug                  Proyecto             WirelessDiagLog.csv        eula.2052.txt  install.res.1036.dll  pagefile.sys

coca@COCA-PC /c
$ cd Desk/Trabajo/S
SUBTE/    SUBTE.7z

coca@COCA-PC /c
$ cd Desk/Trabajo/SUBTE

coca@COCA-PC /c/Desk/Trabajo/SUBTE
$ cd A
ATP/    ATP.7z

coca@COCA-PC /c/Desk/Trabajo/SUBTE
$ cd ATP

coca@COCA-PC /c/Desk/Trabajo/SUBTE/ATP
$ ls
BackUp  build-proyecto_subtes-Desktop_Qt_5_5_0_MinGW_32bit2-Debug  proyecto_subtes

coca@COCA-PC /c/Desk/Trabajo/SUBTE/ATP
$ cd proyecto_subtes/

coca@COCA-PC /c/Desk/Trabajo/SUBTE/ATP/proyecto_subtes (mm-ATP-v0.3)
$ git status
On branch mm-ATP-v0.3
nothing to commit, working directory clean

coca@COCA-PC /c/Desk/Trabajo/SUBTE/ATP/proyecto_subtes (mm-ATP-v0.3)
$ git status
On branch mm-ATP-v0.3
nothing to commit, working directory clean

coca@COCA-PC /c/Desk/Trabajo/SUBTE/ATP/proyecto_subtes (mm-ATP-v0.3)
$ git push origin mm
mm-ATP-v0.3             mm-FixDeployDirectX-9

coca@COCA-PC /c/Desk/Trabajo/SUBTE/ATP/proyecto_subtes (mm-ATP-v0.3)
$ git push origin mm-ATP-v0.3
Username for 'https://github.com': amaurisur
Password for 'https://amaurisur@github.com':
To https://github.com/Subtes/proyecto_subtes.git
 ! [rejected]        mm-ATP-v0.3 -> mm-ATP-v0.3 (non-fast-forward)
error: failed to push some refs to 'https://github.com/Subtes/proyecto_subtes.git'
hint: Updates were rejected because the tip of your current branch is behind
hint: its remote counterpart. Integrate the remote changes (e.g.
hint: 'git pull ...') before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.

coca@COCA-PC /c/Desk/Trabajo/SUBTE/ATP/proyecto_subtes (mm-ATP-v0.3)
$ git push --help
Launching default browser to display HTML ...

coca@COCA-PC /c/Desk/Trabajo/SUBTE/ATP/proyecto_subtes (mm-ATP-v0.3)
$