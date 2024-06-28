sonar-scanner  \
  -Dsonar.organization=hungminhtran \
  -Dsonar.projectKey=hungminhtran_cppdemo \
  -Dsonar.sources=./src \
  -Dsonar.cfamily.build-wrapper-output=bw-output \
  -Dsonar.cfamily.compile_commands=./bw-output/compile_commands.json \
  -Dsonar.host.url=https://sonarcloud.io

