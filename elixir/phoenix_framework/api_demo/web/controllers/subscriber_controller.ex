defmodule ApiDemo.Api.V1.SubscriberController do
  use ApiDemo.Web, :controller
  alias ApiDemo.Subscriber

  plug :action

  def index conn, _ do
    subscribers = Subscriber.list
    render conn, subscribers: subscribers
    #json conn, subscribers
  end

  # def edit(conn, _params) do
  # end

  # def new(conn, _params) do
  # end

  def show conn, params do
    subscriber = Subscriber.get %{phone_number: params["phone_number"]}
    render conn, subscriber: subscriber
    #json conn, [subscriber]
  end

  # def create(conn, _params) do
  # end

  # def update(conn, _params) do
  # end

  # def delete(conn, _params) do
  # end

end
