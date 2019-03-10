#include <cppdb/frontend.h>
#include <iostream>
#include <ctime>

int main()
{
	try {
		cppdb::session sql("mysql:database=test;user=root;password=test");
		
        sql << "set names utf8;" << cppdb::exec;
		sql << "DROP TABLE IF EXISTS test;" << cppdb::exec;

		sql<<	"CREATE TABLE test ( "
			"   `id` int(11) NOT NULL AUTO_INCREMENT, "
			"   `name` varchar(10) NOT NULL,"
			"   `content` varchar(12) CHARACTER SET utf8mb4 NOT NULL, "
            "   `create_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT '创建时间',"
			"   PRIMARY KEY (`id`)"
			")  ENGINE=InnoDB DEFAULT CHARSET=utf8; " << cppdb::exec;
		
		std::time_t now_time = std::time(0);
		
		std::tm now = *std::localtime(&now_time);

		cppdb::statement stat;
		
		stat = sql << 
			"INSERT INTO test(name, content, create_time) "
			"VALUES(?,?,?)"
			<< "spring" << "test" << now;

		stat.exec();
		std::cout<<"ID: "<<stat.last_insert_id() << std::endl;
		std::cout<<"Affected rows "<<stat.affected()<<std::endl;
		
		stat.reset();

		stat.bind("liming");
		stat.bind("Hello 'World'");
        stat.bind(now);
		stat.exec();


		cppdb::result res = sql << "SELECT id,name,content,create_time FROM test";

		while(res.next()) {
			int id;
			std::tm create_time;
			std::string name;
            std::string content;
			res >> id >> name >> content >> create_time;
			std::cout << id << ' ' << name << ' ' << content << ' ' << asctime(&create_time) << std::endl;
		}

		res = sql << "SELECT name,content FROM test WHERE id=?" << 2 << cppdb::row;
		if(!res.empty()) {
			std::string n = res.get<std::string>("name");
			std::string f=res.get<std::string>(1);
			std::cout << "The values are " << n <<" " << f << std::endl;
		}
	}
	catch(std::exception const &e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
