#!/bin/bash

/usr/local/bin/reader &

soffice "-accept=socket,host=localhost,port=2083;urp;StarOffice.ServiceManager"
sleep 20
export LD_LIBRARY_PATH=/usr/lib/ure/lib:$LD_LIBRARY_PATH
/usr/local/bin/faciltyGui


