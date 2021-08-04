set plogPath="D:\sasha\temp\gits\fwProjectTemplate\build\logs\pvs-studio\test.plog"
CLMonitor.exe monitor
waitfor aaa /t 5 2> NUL
ceedling clean & ceedling release & CLMonitor.exe analyze -l %plogPath%
