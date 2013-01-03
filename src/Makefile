include ${CONF_FILE}

DIRS=${shell ls -d */}

MK=GNUMakefile

all: ${DIRS:%/=%.dir}


%.dir:
	@make -f ../../etc/Common.${MK} -C $*
 
