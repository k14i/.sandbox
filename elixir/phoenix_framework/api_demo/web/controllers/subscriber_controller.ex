defmodule ApiDemo.Api.V1.SubscriberController do
  use ApiDemo.Web, :controller
  alias ApiDemo.Repo
  alias ApiDemo.Subscriber

  plug :action

  def index(conn, _params) do
    subscribers = Repo.all(Subscriber)
    render conn, subscribers: subscribers
  end

  # def edit(conn, _params) do
  # end

  # def new(conn, _params) do
  # end

  def show(conn, params) do
    subscriber = Repo.get_by(Subscriber, phone_number: params["phone_number"])
    render conn, subscribers: subscriber
  end

  # def create(conn, _params) do
  # end

  # def update(conn, _params) do
  # end

  # def delete(conn, _params) do
  # end

end
