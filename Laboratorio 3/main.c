#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>

bool execute_command(char *command[]){
    if(!strcmp(command[0], "exit")){
        return false;
    }

    pid_t pid;
    pid = fork();
    char *argv[] = {command[0],NULL};

    if(pid == -1 ){
        printf("Error al ejecutar el comando (⊙ө⊙)!\n");
        exit(0);
    }

    if(pid){
        //Proceso padre
        waitpid(pid,NULL,0);
    }
    else {
        //Proceso hijo
        if(execvp(command[0], argv) == -1)
            printf("Comando no existe (⊙ө⊙)!\n");
    }

    return true;
}

std::pair<char **, size_t> string_vector_to_char_array(std::vector<std::string> sv){
    char **ch_array = new char *[sv.size()];

    for(int i = 0; i < sv.size(); i++){
        std::string str = sv[0];

        char c_str[str.length()];
        strcpy(c_str, str.c_str());
    }

    return std::make_pair(ch_array, sv.size());
}

std::vector<std::string> parse_user_input(std::string line){
    std::stringstream line_stream(line);

    std::vector<std::string> segments;
    std::string current_segment;

    while(std::getline(line_stream, current_segment, ' ')){
        segments.push_back(current_segment);
    }

    return segments;
}

bool display_prompt(){
    string user_input;

    printf("( ˘ ⊖ ˘)/? " );



    auto segments = parse_user_input(line);
    /*
    for(auto& segment: segments){
        std::cout << segment << std::endl;
    }*/

    char *argv[1];
    argv[0] = (char *) segments[0].c_str();


    if(segments.size() == 0){
        return true;
    }

    return execute_command(argv);

//    int result = segments[0].compare("exit");
//    return (result != 0);
//
//    return true;
}


int main(int argc, char **argv){
    while(display_prompt());

    return 0;
}