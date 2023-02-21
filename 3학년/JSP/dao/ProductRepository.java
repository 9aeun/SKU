package dao;

import java.sql.Connection;
import java.util.ArrayList;

import dto.Product;

public class ProductRepository {

	private ArrayList<Product> listOfProducts = new ArrayList<Product>();
	private static ProductRepository instance = new ProductRepository();
	
	public static ProductRepository getInstance() {
		return instance;
	}
	
	public ProductRepository() {
		Product p1=new Product("D001", "저칼로리 스위트 칠리 소스", 2780, "진짜 저칼로리! 100g당 30kcal\n 칼로리는 낮게, 스위트 칠리의 맛은 그대로!", "소스", "동원홈푸드", 84 ,280, "D001.png");
		Product p2=new Product("D002", "저칼로리 토마토케첩", 2580, "진짜 저칼로리! 100g당 30kcal\n 칼로리는 낮게, 토마토 케첩의 맛은 그대로!", "소스", "동원홈푸드", 98, 280,"D002.png");
		Product p3=new Product("D003", "저칼로리 머스타드", 2780, "진짜 저칼로리! 100g당 37.4kcal\n 칼로리는 낮게, 머스타드 소스의 맛은 그대로!", "소스", "동원홈푸드", 104.7,280, "D003.png");
		Product p4=new Product("D004", "저칼로리 비빔장", 3480, "비빔면 먹고 싶은 사람 손~!\n 저칼로리 비빔장 듬뿍 넣어도 16kcal!(45g당)\n 진짜 저칼로리 & 저당 매콤, 달콤, 새콤한 맛은 그대로!", "소스", "동원홈푸드", 99.2,280, "D004.png");
		Product p5=new Product("D005", "곤약면", 1500, "부담없이 맛있게 먹는 저칼로리 곤약면", "면", "동원홈푸드", 24, 200, "D005.png");
		Product p6=new Product("D006", "비건마요", 4980, "동물성원료 NO, 고소한 맛 YES\n 비건인증 완료한 진짜 비건 제품", "소스","동원홈푸드",1300, 250, "D006.png");
		Product p7=new Product("D007", "곤약죽 닭가슴살 & 두부", 2480, "곤약과 건강한 곡물을 담아 맛있게 가벼운 한끼! \n담백한 닭가슴살과 두부 듬뿍!","밥","동원홈푸드", 50, 150, "D007.png");
		Product p8=new Product("D008", "곤약리조또 스파이시 토마토 & 닭가슴살", 2480, "곤약과 건강한 곡물을 담아 맛있게 가벼운 한끼! \n향긋한 토마토에 매콤함을 톡톡","밥", "동원홈푸드",85, 150, "D008.png");
		Product p9=new Product("D009", "곤약리조또 트러플&버섯", 2480,"곤약과 건강한 곡물을 담아 맛있게 가벼운 한 끼! \n화이트트러플 풍미 가득!", "밥", "동원홈푸드", 100,150,"D009.png" );
		Product p10=new Product("D010", "저칼로리 바베큐 소스", 2780,"진짜 저칼로리! 100g당 38.5kcal\n 칼로리는 낮게, 바베큐 소스의 맛은 그대로!", "소스", "동원홈푸드", 107.8, 280, "D010.png");

		listOfProducts.add(p1);
		listOfProducts.add(p2);
		listOfProducts.add(p3);
		listOfProducts.add(p4);
		listOfProducts.add(p5);
		listOfProducts.add(p6);
		listOfProducts.add(p7);
		listOfProducts.add(p8);
		listOfProducts.add(p9);
		listOfProducts.add(p10);
	}
	

	public Product getProductById(String productId) {
		Product productById = null;
		
		for(int i=0; i<listOfProducts.size(); i++) {
			Product product=listOfProducts.get(i);
			if(product!=null && product.getProductId()!=null&&product.getProductId().equals(productId)) {
				productById=product;
				break;
			}
		}
		return productById;
	}
	
	public ArrayList<Product> getAllProducts(){
		return listOfProducts;
	}
	
	public void addProduct(Product product) {
		listOfProducts.add(product);
	}
	

}

