pipeline {
  agent none
  stages{
    stage('CLooG'){
      matrix{
        agent{ label "${OS}" }
        axes{
          axis{
            name 'OS'
            values 'Ubuntu', 'macOS', 'CentOS', 'fedora', 'Debian'
          }
          axis{
            name 'BuildSystem'
            values 'GNU Autotools'//, 'CMake'
          }
        }
        stages{
          stage('Tools'){
            steps{
              script{
                if(env.OS == 'Ubuntu')
                  sh 'sudo apt install texlive texlive-generic-recommended autotools-dev autoconf -y'
                if(env.OS == 'macOS')
                  sh 'brew install automake libtool'
                if(env.OS == 'CentOS')
                  sh 'sudo yum install gmp-devel -y'
                if(env.OS == 'fedora')
                  sh 'sudo dnf install gmp-devel -y'
                if(env.OS == 'Debian')
                  sh 'sudo apt install autoconf libtool libgmp-dev make texlive -y'
              }
            }
          }
          stage('Build'){
            steps{
              script{
                if(env.BuildSystem == 'GNU Autotools')
                  sh './get_submodules.sh && ./autogen.sh && ./configure --with-isl=bundled --with-osl=bundled && make -j 12'
                if(env.BuildSystem == 'CMake')
                  sh 'mkdir build && cd build && cmake .. && cmake --build'
              }
            }
          }
          stage('Test'){
            steps{
              script {
                if(env.BuildSystem == 'GNU Autotools')
                  sh 'make check -j'
                if(env.BuildSystem == 'CMake')
                  sh 'cd build && cmake --build . --target check'
              }
            }
          }
        }
      }
    }
  }
}
