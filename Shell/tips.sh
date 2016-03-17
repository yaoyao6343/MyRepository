################################################################################
# Print text with different color.
################################################################################
red="\033[31m"
green="\033[32m"
white="\033[0m"

print red+"Not a valid atca host name or IP addr"+white

################################################################################
# Use loop
################################################################################
#!/bin/bash
for i in {1..20}
do
    echo $i
done

#!/bin/bash
man_cases=("NG35543ESPE06" "NG43042ESPE07")

for c in ${man_cases[@]}; do
    echo $c
done

#!/bin/bash
result=`cat $1`
for item in ${result}; do
    echo "---------- ${item} ----------"
    sleep 1
done



