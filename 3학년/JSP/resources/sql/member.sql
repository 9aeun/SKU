CREATE TABLE member(
	id varchar(10) not null,		
	password varchar(10) not null,	
	name varchar(10) not null,		
	gender varchar(4),			
	birth varchar(10),			
	mail varchar(30),			
	phone varchar(20),
	zipcode varchar(10),
	address varchar(30),
	detailAddress varchar(30),
	reference varchar(30),
	regist_day varchar(50),			
	primary key(id)				
) default CHARSET=utf8;

DESC member;

select * from member;

delete from member where password='';
