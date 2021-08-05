


while getopts "n:h" optname
do
    case "$optname" in
      "n")
        CLIENTNUM=$OPTARG
        ;;
       "h")
        echo "eg:./run.sh -n <client_num>"
	exit 0
        ;;
      ":")
        echo "No argument value for option $OPTARG"
        ;;
      "?")
        echo "Unknown option $OPTARG"
        ;;
      *)
        echo "Unknown error while processing options"
        ;;
    esac
done

if [ $# -eq 0 ]
then
	echo "client_num not specified! eg:./run.sh -n <client_num>"
	exit -1
fi

N=0
while [ $N -lt $CLIENTNUM ]
do
	./test &
	let N++
done
