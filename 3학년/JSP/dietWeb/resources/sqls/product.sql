CREATE table IF NOT EXISTS product(
	p_id VARCHAR(10) NOT NULL,
	p_name VARCHAR(40),
	p_unitPrice INTEGER,
	p_description TEXT,
	p_category VARCHAR(20),
	p_manufacturer VARCHAR(20),
	p_calorie FLOAT,
	p_volume INTEGER,
	p_filename VARCHAR(20),
	PRIMARY KEY (p_id)
)default CHARSET=utf8;

desc product;

