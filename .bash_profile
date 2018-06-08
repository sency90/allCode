#!/bin/bash
export PS1="\[\033[36m\]\u\[\033[m\]@\[\033[32m\]\h:\[\033[33;1m\]\w\[\033[m\]\$ "
export CLICOLOR=1
export LSCOLORS=ExFxBxDxCxegedabagacad
export JAVA_HOME=$(/usr/libexec/java_home)
#alias ls='ls -GFh'
alias pb='pbcopy <'

alias mk='make'
alias mkc='make c'
alias mkcc='make cc'
alias mkc11='make c11'
alias mkc14='make c14'
alias mkj='make java'
alias mkin='make < in.txt'

export BS=~/.submit/bin/
export PATH=${PATH}:${BS}
alias gbs='gmail_baekjoon_submit'
alias ibs='icloud_baekjoon_submit'

# added by Anaconda3 4.0.0 installer
export PATH="/Users/lian/anaconda/bin:$PATH"

export PATH="/usr/local/mysql/bin:$PATH"

export PATH=$PATH:/usr/local/hybus-arm-linux-R1.1/bin/

export PATH=$PATH:/Users/lian/spark/spark-1.6.1/bin/

# pyspark setting
export SPARK_HOME="$HOME/spark/spark-1.6.1"
export PYSPARK_SUBMIT_ARGS="--master local[2]"
export IPYTHON=1
export PYSPARK_PYTHON=/usr/local/bin/python3.5
export PYSPARK_DRIVER_PYTHON=ipython3
alias ipy="IPYTHON=1 $SPARK_HOME/bin/pyspark"
alias ss="spark-submit"
# export PYSPARK_DRIVER_PYTHON_OPTS="notebook"

##
# Your previous /Users/lian/.bash_profile file was backed up as /Users/lian/.bash_profile.macports-saved_2016-09-11_at_18:58:32
##

# MacPorts Installer addition on 2016-09-11_at_18:58:32: adding an appropriate PATH variable for use with MacPorts.
export PATH="/opt/local/bin:/opt/local/sbin:$PATH"
# Finished adapting your PATH environment variable for use with MacPorts.

alias moss='~/Program/moss/moss.pl'

eval $(/usr/libexec/path_helper -s)
